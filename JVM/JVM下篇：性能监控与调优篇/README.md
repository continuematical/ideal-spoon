> 笔记来源：[尚硅谷 JVM 全套教程，百万播放，全网巅峰（宋红康详解 java 虚拟机）](https://www.bilibili.com/video/BV1PJ411n7xZ "尚硅谷JVM全套教程，百万播放，全网巅峰（宋红康详解java虚拟机）")
>
> 同步更新：https://gitee.com/vectorx/NOTE_JVM
>
> https://codechina.csdn.net/qq_35925558/NOTE_JVM
>
> https://github.com/uxiahnan/NOTE_JVM

[TOC]

# 1. 概述篇

## 1.1. 大厂面试题

> <mark>支付宝：</mark>
>
> 支付宝三面：JVM 性能调优都做了什么？
>
> <mark>小米：</mark>
>
> 有做过 JVM 内存优化吗？
>
> 从 SQL、JVM、架构、数据库四个方面讲讲优化思路
>
> <mark>蚂蚁金服：</mark>
>
> JVM 的编译优化
>
> jvm 性能调优都做了什么
>
> JVM 诊断调优工具用过哪些？
>
> 二面：jvm 怎样调优，堆内存、栈空间设置多少合适
>
> 三面：JVM 相关的分析工具使用过的有哪些？具体的性能调优步骤如何
>
> <mark>阿里：</mark>
>
> 如何进行 JVM 调优？有哪些方法？
>
> 如何理解内存泄漏问题？有哪些情况会导致内存泄漏？如何解决？
>
> <mark>字节跳动：</mark>
>
> 三面：JVM 如何调优、参数怎么调？
>
> <mark>拼多多：</mark>
>
> 从 SQL、JVM、架构、数据库四个方面讲讲优化思路
>
> <mark>京东：</mark>
>
> JVM 诊断调优工具用过哪些？
>
> 每秒几十万并发的秒杀系统为什么会频繁发生 GC？
>
> 日均百万级交易系统如何优化 JVM？
>
> 线上生产系统 OOM 如何监控及定位与解决？
>
> 高并发系统如何基于 G1 垃圾回收器优化性能？

## 1.2. 背景说明

**生产环境中的问题**

- 生产环境发生了内存溢出该如何处理？
- 生产环境应该给服务器分配多少内存合适？
- 如何对垃圾回收器的性能进行调优？
- 生产环境 CPU 负载飙高该如何处理？
- 生产环境应该给应用分配多少线程合适？
- 不加 log，如何确定请求是否执行了某一行代码？
- 不加 log，如何实时查看某个方法的入参与返回值？

**为什么要调优**

- 防止出现 OOM
- 解决 OOM
- 减少 Full GC 出现的频率

**不同阶段的考虑**

- 上线前
- 项目运行阶段
- 线上出现 OOM

## 1.3. 调优概述

**监控的依据**

- 运行日志
- 异常堆栈
- GC 日志
- 线程快照
- 堆转储快照

**调优的大方向**

- 合理地编写代码
- 充分并合理的使用硬件资源
- 合理地进行 JVM 调优

## 1.4. 性能优化的步骤

**第 1 步：性能监控**

一种非强行或入侵方式收集和查看应用运营性能数据的活动。

- GC 频繁
- cpu load 过高
- OOM
- 内存泄露
- 死锁
- 程序响应时间较长

**第 2 步：性能分析**

一种以侵入方式收集运行性能数据的活动，它会影响应用的吞吐量或相应性。

- 打印 GC 日志，通过 GCviewer 或者 http://gceasy.io 来分析异常信息
- 灵活运用命令行工具、jstack、jmap、jinfo 等
- dump 出堆文件，使用内存分析工具分析文件
- 使用阿里 Arthas、jconsole、JVisualVM 来实时查看 JVM 状态
- jstack 查看堆栈信息

**第 3 步：性能调优**

- 适当增加内存，根据业务背景选择垃圾回收器
- 优化代码，控制内存使用
- 增加机器，分散节点压力
- 合理设置线程池线程数量
- 使用中间件提高程序效率，比如缓存、消息队列等
- 其他……

## 1.5. 性能评价/测试指标

 **停顿时间（或响应时间）**

提交请求和返回该请求的响应之间使用的时间，一般比较关注平均响应时间。常用操作的响应时间列表：

| 操作                                | 响应时间 |
| :---------------------------------- | :------- |
| 打开一个站点                        | 几秒     |
| 数据库查询一条记录（有索引）        | 十几毫秒 |
| 机械磁盘一次寻址定位                | 4 毫秒   |
| 从机械磁盘顺序读取 1M 数据          | 2 毫秒   |
| 从 SSD 磁盘顺序读取 1M 数据         | 0.3 毫秒 |
| 从远程分布式换成 Redis 读取一个数据 | 0.5 毫秒 |
| 从内存读取 1M 数据                  | 十几微妙 |
| Java 程序本地方法调用               | 几微妙   |
| 网络传输 2Kb 数据                   | 1 微妙   |

在垃圾回收环节中：

- 暂停时间：执行垃圾收集时，程序的工作线程被暂停的时间。
- $-XX:MaxGCPauseMillis$ 设置最大暂停时间。

**吞吐量**

- 对单位时间内完成的工作量（请求）的量度；
- 在 GC 中：运行用户代码的事件占总运行时间的比例（总运行时间：程序的运行时间+内存回收的时间）
- 吞吐量为 $1-1/(1+n)$，其中 $-XX::GCTimeRatio=n$ 

**并发数**

- 同一时刻，对服务器有实际交互的请求数；

**内存占用**

- $Java$ 堆区所占的内存大小；

**相互间的关系**

以高速公路通行状况为例

- 吞吐量：每天通过高速公路收费站的车辆的数据
- 并发数：高速公路上正在行驶的车辆的数目
- 响应时间：车速

<hr/>

# 2. JVM 监控及诊断工具-命令行篇

## 2.1. 概述

性能诊断是软件工程师在日常工作中需要经常面对和解决的问题，在用户体验至上的今天，解决好应用的性能问题能带来非常大的收益。

Java 作为最流行的编程语言之一，其应用性能诊断一直受到业界广泛关注。可能造成 Java 应用出现性能问题的因素非常多，例如线程控制、磁盘读写、数据库访问、网络 I/O、垃圾收集等。想要定位这些问题，一款优秀的性能诊断工具必不可少。

体会 1：使用数据说明问题，使用知识分析问题，使用工具处理问题。

体会 2：无监控、不调优！

**简单命令行工具**

在我们刚接触 java 学习的时候，大家肯定最先了解的两个命令就是 javac，java，那么除此之外，还有没有其他的命令可以供我们使用呢？

我们进入到安装 jdk 的 bin 目录，发现还有一系列辅助工具。这些辅助工具用来获取目标 JVM 不同方面、不同层次的信息，帮助开发人员很好地解决 Java 应用程序的一些疑难杂症。

![image-20210504195803526](https://img-blog.csdnimg.cn/img_convert/5b7c5d239e4da192ba65edb0800055c5.png)

![image-20210504195836342](https://img-blog.csdnimg.cn/img_convert/fa3c5e41cbf999d261bcf32851731565.png)

官方源码地址：[http://hg.openjdk.java.net/jdk/jdk11/file/1ddf9a99e4ad/src/jdk.jcmd/share/classes/sun/tools](http://hg.openjdk.java.net/jdk/jdk11/file/1ddf9a99e4ad/src/jdk.jcmd/share/classes/sun/tools)

## 2.2. jps：查看正在运行的 Java 进程

jps(Java Process Status)：显示指定系统内所有的 HotSpot 虚拟机进程（查看虚拟机进程信息），可用于查询正在运行的虚拟机进程。

说明：对于本地虚拟机进程来说，进程的本地虚拟机 ID 与操作系统的进程 ID 是一致的，是唯一的。

基本使用语法为：jps [options] [hostid]

我们还可以通过追加参数，来打印额外的信息。

**options 参数**

- -q：仅仅显示 LVMID（local virtual machine id），即本地虚拟机唯一 id。不显示主类的名称等
- -l：输出应用程序主类的全类名 或 如果进程执行的是 jar 包，则输出 jar 完整路径
- -m：输出虚拟机进程启动时传递给主类 main()的参数
- -v：列出虚拟机进程启动时的 JVM 参数。比如：-Xms20m -Xmx50m 是启动程序指定的 jvm 参数。

说明：以上参数可以综合使用。

补充：如果某 Java 进程关闭了默认开启的 UsePerfData 参数（即使用参数-XX：-UsePerfData），那么 jps 命令（以及下面介绍的 jstat）将无法探知该 Java 进程。

**hostid 参数**

RMI 注册表中注册的主机名。如果想要远程监控主机上的 java 程序，需要安装 jstatd。

对于具有更严格的安全实践的网络场所而言，可能使用一个自定义的策略文件来显示对特定的可信主机或网络的访问，尽管这种技术容易受到 IP 地址欺诈攻击。

如果安全问题无法使用一个定制的策略文件来处理，那么最安全的操作是不运行 jstatd 服务器，而是在本地使用 jstat 和 jps 工具。

## 2.3. jstat：查看 JVM 统计信息

jstat（JVM Statistics Monitoring Tool）：用于监视虚拟机各种运行状态信息的命令行工具。它可以显示本地或者远程虚拟机进程中的类装载、内存、垃圾收集、JIT 编译等运行数据。在没有 GUI 图形界面，只提供了纯文本控制台环境的服务器上，它将是运行期定位虚拟机性能问题的首选工具。常用于检测垃圾回收问题以及内存泄漏问题。

官方文档：[https://docs.oracle.com/javase/8/docs/technotes/tools/unix/jstat.html](https://docs.oracle.com/javase/8/docs/technotes/tools/unix/jstat.html)

基本使用语法为：jstat -&lt;option&gt; [-t] [-h&lt;lines&gt;] &lt;vmid&gt; [&lt;interval&gt; [&lt;count&gt;]]

查看命令相关参数：jstat-h 或 jstat-help

其中 vmid 是进程 id 号，也就是 jps 之后看到的前面的号码，如下：

![image-20210504201703222](https://img-blog.csdnimg.cn/img_convert/83dddc874824b88d7fd03dab2b3889f1.png)

**option 参数**

选项 option 可以由以下值构成。

<mark>类装载相关的：</mark>

- -class：显示 ClassLoader 的相关信息：类的装载、卸载数量、总空间、类装载所消耗的时间等

<mark>垃圾回收相关的：</mark>

- -gc：显示与 GC 相关的堆信息。包括 Eden 区、两个 Survivor 区、老年代、永久代等的容量、已用空间、GC 时间合计等信息。
- -gccapacity：显示内容与-gc 基本相同，但输出主要关注 Java 堆各个区域使用到的最大、最小空间。
- -gcutil：显示内容与-gc 基本相同，但输出主要关注已使用空间占总空间的百分比。
- -gccause：与-gcutil 功能一样，但是会额外输出导致最后一次或当前正在发生的 GC 产生的原因。
- -gcnew：显示新生代 GC 状况
- -gcnewcapacity：显示内容与-gcnew 基本相同，输出主要关注使用到的最大、最小空间
- -geold：显示老年代 GC 状况
- -gcoldcapacity：显示内容与-gcold 基本相同，输出主要关注使用到的最大、最小空间
- -gcpermcapacity：显示永久代使用到的最大、最小空间。

<mark>JIT 相关的：</mark>

- -compiler：显示 JIT 编译器编译过的方法、耗时等信息
- -printcompilation：输出已经被 JIT 编译的方法

**jstat -class**

![img](https://img-blog.csdnimg.cn/img_convert/9f2cea8b0a9b1bc47c10281b5c140cc4.png)

**jstat -compiler**

![img](https://img-blog.csdnimg.cn/img_convert/4e11a07ce9b8ff2f73ba5585e11e1da3.png)

**jstat -printcompilation**

![img](https://img-blog.csdnimg.cn/img_convert/2a2553eef35293d28ef095feee3bb3b7.png)

**jstat -gc**

![img](https://img-blog.csdnimg.cn/img_convert/6ea2aa6665c49b4bd35d46152dd2f1aa.png)

**jstat -gccapacity**

![img](https://img-blog.csdnimg.cn/img_convert/be1dbc9fb1100c4ab76fdf802171c000.png)

**jstat -gcutil**

![img](https://img-blog.csdnimg.cn/img_convert/527f347102e0f48036f4e643103a735f.png)

**jstat -gccause**

![img](https://img-blog.csdnimg.cn/img_convert/2e5d220a3ceb094b3d6aee8b46867942.png)

**jstat -gcnew**

![img](https://img-blog.csdnimg.cn/img_convert/766a9d8c98c1add9ff60f001fcbe552b.png)

**jstat -gcnewcapacity**

![img](https://img-blog.csdnimg.cn/img_convert/d26356900de541c149df9c00852245a1.png)

**jstat -gcold**

![img](https://img-blog.csdnimg.cn/img_convert/64f18adec84996fec58edf7052440610.png)

**jstat -gcoldcapacity**

![img](https://img-blog.csdnimg.cn/img_convert/52bf3b50ba4a48247742caa0aa30be7e.png)

**jstat -t**

![img](https://img-blog.csdnimg.cn/img_convert/61a5c6b9c421ba9ec38db1f132ef4161.png)

**jstat -t -h**

![img](https://img-blog.csdnimg.cn/img_convert/73a294c043f770940daa6a501c1e8d2c.png)

| 表头 | 含义（字节）                                      |
| :--- | :------------------------------------------------ |
| EC   | Eden 区的大小                                     |
| EU   | Eden 区已使用的大小                               |
| S0C  | 幸存者 0 区的大小                                 |
| S1C  | 幸存者 1 区的大小                                 |
| S0U  | 幸存者 0 区已使用的大小                           |
| S1U  | 幸存者 1 区已使用的大小                           |
| MC   | 元空间的大小                                      |
| MU   | 元空间已使用的大小                                |
| OC   | 老年代的大小                                      |
| OU   | 老年代已使用的大小                                |
| CCSC | 压缩类空间的大小                                  |
| CCSU | 压缩类空间已使用的大小                            |
| YGC  | 从应用程序启动到采样时 young gc 的次数            |
| YGCT | 从应用程序启动到采样时 young gc 消耗时间（秒）    |
| FGC  | 从应用程序启动到采样时 full gc 的次数             |
| FGCT | 从应用程序启动到采样时的 full gc 的消耗时间（秒） |
| GCT  | 从应用程序启动到采样时 gc 的总时间                |

**interval 参数：** 用于指定输出统计数据的周期，单位为毫秒。即：查询间隔

**count 参数：** 用于指定查询的总次数

**-t 参数：** 可以在输出信息前加上一个 Timestamp 列，显示程序的运行时间。单位：秒

**-h 参数：** 可以在周期性数据输出时，输出多少行数据后输出一个表头信息

**补充：** jstat 还可以用来判断是否出现内存泄漏。

第 1 步：在长时间运行的 Java 程序中，我们可以运行 jstat 命令连续获取多行性能数据，并取这几行数据中 OU 列（即已占用的老年代内存）的最小值。

第 2 步：然后，我们每隔一段较长的时间重复一次上述操作，来获得多组 OU 最小值。如果这些值呈上涨趋势，则说明该 Java 程序的老年代内存已使用量在不断上涨，这意味着无法回收的对象在不断增加，因此很有可能存在内存泄漏。

## 2.4. jinfo：实时查看和修改 JVM 配置参数

jinfo(Configuration Info for Java)：查看虚拟机配置参数信息，也可用于调整虚拟机的配置参数。在很多情况卡，Java 应用程序不会指定所有的 Java 虚拟机参数。而此时，开发人员可能不知道某一个具体的 Java 虚拟机参数的默认值。在这种情况下，可能需要通过查找文档获取某个参数的默认值。这个查找过程可能是非常艰难的。但有了 jinfo 工具，开发人员可以很方便地找到 Java 虚拟机参数的当前值。

基本使用语法为：jinfo [options] pid

说明：java 进程 ID 必须要加上

| 选项             | 选项说明                                                     |
| ---------------- | ------------------------------------------------------------ |
| no option        | 输出全部的参数和系统属性                                     |
| -flag name       | 输出对应名称的参数                                           |
| -flag [+-]name   | 开启或者关闭对应名称的参数 只有被标记为 manageable 的参数才可以被动态修改 |
| -flag name=value | 设定对应名称的参数                                           |
| -flags           | 输出全部的参数                                               |
| -sysprops        | 输出系统属性                                                 |

**jinfo -sysprops**

```properties
> jinfo -sysprops
jboss.modules.system.pkgs = com.intellij.rt
java.vendor = Oracle Corporation
sun.java.launcher = SUN_STANDARD
sun.management.compiler = HotSpot 64-Bit Tiered Compilers
catalina.useNaming = true
os.name = Windows 10
...
```

**jinfo -flags**

```shell
> jinfo -flags 25592
Non-default VM flags: -XX:CICompilerCount=4 -XX:InitialHeapSize=333447168 -XX:MaxHeapSize=5324668928 -XX:MaxNewSize=1774714880 -XX:MinHeapDeltaBytes=524288 -XX:NewSize=111149056 -XX:OldSize=222298112 -XX:+UseCompressedClassPointers -XX:+UseCompressedOops -XX:+UseFastUnorderedTimeStamps -XX:-UseLargePagesIndividualAllocation -XX:+UseParallelGC
Command line:  -agentlib:jdwp=transport=dt_socket,address=127.0.0.1:8040,suspend=y,server=n -Drebel.base=C:\Users\Vector\.jrebel -Drebel.env.ide.plugin.version=2021.1.2 -Drebel.env.ide.version=2020.3.3 -Drebel.env.ide.product=IU -Drebel.env.ide=intellij -Drebel.notification.url=http://localhost:7976 -agentpath:C:\Users\Vector\AppData\Roaming\JetBrains\IntelliJIdea2020.3\plugins\jr-ide-idea\lib\jrebel6\lib\jrebel64.dll -Dmaven.home=D:\eclipse\env\maven -Didea.modules.paths.file=C:\Users\Vector\AppData\Local\JetBrains\IntelliJIdea2020.3\Maven\idea-projects-state-596682c7.properties -Dclassworlds.conf=C:\Users\Vector\AppData\Local\Temp\idea-6755-mvn.conf -Dmaven.ext.class.path=D:\IDEA\plugins\maven\lib\maven-event-listener.jar -javaagent:D:\IDEA\plugins\java\lib\rt\debugger-agent.jar -Dfile.encoding=UTF-8
```

**jinfo -flag**

```shell
> jinfo -flag UseParallelGC 25592
-XX:+UseParallelGC

> jinfo -flag UseG1GC 25592
-XX:-UseG1GC
```

**jinfo -flag name**

```shell
> jinfo -flag UseParallelGC 25592
-XX:+UseParallelGC

> jinfo -flag UseG1GC 25592
-XX:-UseG1GC
```

**jinfo -flag [+-]name**

```shell
> jinfo -flag +PrintGCDetails 25592
> jinfo -flag PrintGCDetails 25592
-XX:+PrintGCDetails

> jinfo -flag -PrintGCDetails 25592
> jinfo -flag PrintGCDetails 25592
-XX:-PrintGCDetails
```

拓展：

- java -XX:+PrintFlagsInitial 查看所有 JVM 参数启动的初始值

  ```shell
  [Global flags]
       intx ActiveProcessorCount                      = -1                                  {product}
      uintx AdaptiveSizeDecrementScaleFactor          = 4                                   {product}
      uintx AdaptiveSizeMajorGCDecayTimeScale         = 10                                  {product}
      uintx AdaptiveSizePausePolicy                   = 0                                   {product}
  ...
  ```

- java -XX:+PrintFlagsFinal 查看所有 JVM 参数的最终值

  ```shell
  [Global flags]
       intx ActiveProcessorCount                      = -1                                  {product}
  ...
       intx CICompilerCount                          := 4                                   {product}
      uintx InitialHeapSize                          := 333447168                           {product}
      uintx MaxHeapSize                              := 1029701632                          {product}
      uintx MaxNewSize                               := 1774714880                          {product}
  ```

- java -XX:+PrintCommandLineFlags 查看哪些已经被用户或者 JVM 设置过的详细的 XX 参数的名称和值

  ```shell
  -XX:InitialHeapSize=332790016 -XX:MaxHeapSize=5324640256 -XX:+PrintCommandLineFlags -XX:+UseCompressedClassPointers -XX:+UseCompressedOops -XX:-UseLargePagesIndividualAllocation -XX:+UseParallelGC
  ```

## 2.5. jmap：导出内存映像文件&内存使用情况

jmap（JVM Memory Map）：作用一方面是获取 dump 文件（堆转储快照文件，二进制文件），它还可以获取目标 Java 进程的内存相关信息，包括 Java 堆各区域的使用情况、堆中对象的统计信息、类加载信息等。开发人员可以在控制台中输入命令“jmap -help”查阅 jmap 工具的具体使用方式和一些标准选项配置。

官方帮助文档：[https://docs.oracle.com/en/java/javase/11/tools/jmap.html](https://docs.oracle.com/en/java/javase/11/tools/jmap.html)

基本使用语法为：

- jmap [option] &lt;pid&gt;
- jmap [option] &lt;executable &lt;core&gt;
- jmap [option] [server_id@] &lt;remote server IP or hostname&gt;

| 选项            | 作用                                                         |
| :-------------- | :----------------------------------------------------------- |
| -dump           | 生成 dump 文件（Java 堆转储快照），-dump:live 只保存堆中的存活对象 |
| -heap           | 输出整个堆空间的详细信息，包括 GC 的使用、堆配置信息，以及内存的使用信息等 |
| -histo          | 输出堆空间中对象的统计信息，包括类、实例数量和合计容量，-histo:live 只统计堆中的存活对象 |
| -J &lt;flag&gt; | 传递参数给 jmap 启动的 jvm                                   |
| -finalizerinfo  | 显示在 F-Queue 中等待 Finalizer 线程执行 finalize 方法的对象，仅 linux/solaris 平台有效 |
| -permstat       | 以 ClassLoader 为统计口径输出永久代的内存状态信息，仅 linux/solaris 平台有效 |
| -F              | 当虚拟机进程对-dump 选项没有任何响应时，强制执行生成 dump 文件，仅 linux/solaris 平台有效 |

说明：这些参数和 linux 下输入显示的命令多少会有不同，包括也受 jdk 版本的影响。

```shell
> jmap -dump:format=b,file=<filename.hprof> <pid>> jmap -dump:live,format=b,file=<filename.hprof> <pid>
```

由于 jmap 将访问堆中的所有对象，为了保证在此过程中不被应用线程干扰，jmap 需要借助安全点机制，让所有线程停留在不改变堆中数据的状态。也就是说，由 jmap 导出的堆快照必定是安全点位置的。这可能导致基于该堆快照的分析结果存在偏差。

举个例子，假设在编译生成的机器码中，某些对象的生命周期在两个安全点之间，那么:live 选项将无法探知到这些对象。

另外，如果某个线程长时间无法跑到安全点，jmap 将一直等下去。与前面讲的 jstat 则不同，垃圾回收器会主动将 jstat 所需要的摘要数据保存至固定位置之中，而 jstat 只需直接读取即可。

## 2.6. jhat：JDK 自带堆分析工具

jhat(JVM Heap Analysis Tool)：Sun JDK 提供的 jhat 命令与 jmap 命令搭配使用，用于分析 jmap 生成的 heap dump 文件（堆转储快照）。jhat 内置了一个微型的 HTTP/HTML 服务器，生成 dump 文件的分析结果后，用户可以在浏览器中查看分析结果（分析虚拟机转储快照信息）。

使用了 jhat 命令，就启动了一个 http 服务，端口是 7000，即 http://localhost:7000/，就可以在浏览器里分析。

说明：jhat 命令在 JDK9、JDK10 中已经被删除，官方建议用 VisualVM 代替。

基本适用语法：jhat &lt;option&gt; &lt;dumpfile&gt;

| option 参数            | 作用                                      |
| :--------------------- | :---------------------------------------- |
| -stack false ｜ true   | 关闭｜打开对象分配调用栈跟踪              |
| -refs false ｜ true    | 关闭｜打开对象引用跟踪                    |
| -port port-number      | 设置 jhat HTTP Server 的端口号，默认 7000 |
| -exclude exclude-file  | 执行对象查询时需要排除的数据成员          |
| -baseline exclude-file | 指定一个基准堆转储                        |
| -debug int             | 设置 debug 级别                           |
| -version               | 启动后显示版本信息就退出                  |
| -J &lt;flag&gt;        | 传入启动参数，比如-J-Xmx512m              |

## 2.7. jstack：打印 JVM 中线程快照

jstack（JVM Stack Trace）：用于生成虚拟机指定进程当前时刻的线程快照（虚拟机堆栈跟踪）。线程快照就是当前虚拟机内指定进程的每一条线程正在执行的方法堆栈的集合。

生成线程快照的作用：可用于定位线程出现长时间停顿的原因，如线程间死锁、死循环、请求外部资源导致的长时间等待等问题。这些都是导致线程长时间停顿的常见原因。当线程出现停顿时，就可以用 jstack 显示各个线程调用的堆栈情况。

官方帮助文档：[https://docs.oracle.com/en/java/javase/11/tools/jstack.html](https://docs.oracle.com/en/java/javase/11/tools/jstack.html)

在 thread dump 中，要留意下面几种状态

- <mark>死锁，Deadlock（重点关注）</mark>
- <mark>等待资源，Waiting on condition（重点关注）</mark>
- <mark>等待获取监视器，Waiting on monitor entry（重点关注）</mark>
- <mark>阻塞，Blocked（重点关注）</mark>
- 执行中，Runnable
- 暂停，Suspended
- 对象等待中，Object.wait() 或 TIMED＿WAITING
- 停止，Parked

| option 参数 | 作用                                         |
| :---------- | :------------------------------------------- |
| -F          | 当正常输出的请求不被响应时，强制输出线程堆栈 |
| -l          | 除堆栈外，显示关于锁的附加信息               |
| -m          | 如果调用本地方法的话，可以显示 C/C++的堆栈   |

## 2.8. jcmd：多功能命令行

在 JDK 1.7 以后，新增了一个命令行工具 jcmd。它是一个多功能的工具，可以用来实现前面除了 jstat 之外所有命令的功能。比如：用它来导出堆、内存使用、查看 Java 进程、导出线程信息、执行 GC、JVM 运行时间等。

官方帮助文档：[https://docs.oracle.com/en/java/javase/11/tools/jcmd.html](https://docs.oracle.com/en/java/javase/11/tools/jcmd.html)

jcmd 拥有 jmap 的大部分功能，并且在 Oracle 的官方网站上也推荐使用 jcmd 命令代 jmap 命令

**jcmd -l：**列出所有的 JVM 进程

**jcmd 进程号 help：**针对指定的进程，列出支持的所有具体命令

![image-20210504213044819](https://img-blog.csdnimg.cn/img_convert/f3507ac3e24d40625f6c3d54c25c743b.png)

**jcmd 进程号 具体命令：**显示指定进程的指令命令的数据

- Thread.print 可以替换 jstack 指令
- GC.class_histogram 可以替换 jmap 中的-histo 操作
- GC.heap_dump 可以替换 jmap 中的-dump 操作
- GC.run 可以查看 GC 的执行情况
- VM.uptime 可以查看程序的总执行时间，可以替换 jstat 指令中的-t 操作
- VM.system_properties 可以替换 jinfo -sysprops 进程 id
- VM.flags 可以获取 JVM 的配置参数信息

## 2.9. jstatd：远程主机信息收集

之前的指令只涉及到监控本机的 Java 应用程序，而在这些工具中，一些监控工具也支持对远程计算机的监控（如 jps、jstat）。为了启用远程监控，则需要配合使用 jstatd 工具。命令 jstatd 是一个 RMI 服务端程序，它的作用相当于代理服务器，建立本地计算机与远程监控工具的通信。jstatd 服务器将本机的 Java 应用程序信息传递到远程计算机。

![image-20210504213301077](https://img-blog.csdnimg.cn/img_convert/2225de448c4af005aa0f72e84bba5e57.png)

<hr/>

# 3. JVM 监控及诊断工具-GUI 篇

## 3.1. 工具概述

使用上一章命令行工具或组合能帮您获取目标 Java 应用性能相关的基础信息，但它们存在下列局限：

- 1．无法获取方法级别的分析数据，如方法间的调用关系、各方法的调用次数和调用时间等（这对定位应用性能瓶颈至关重要）。
- 2．要求用户登录到目标 Java 应用所在的宿主机上，使用起来不是很方便。
- 3．分析数据通过终端输出，结果展示不够直观。

为此，JDK 提供了一些内存泄漏的分析工具，如 jconsole，jvisualvm 等，用于辅助开发人员定位问题，但是这些工具很多时候并不足以满足快速定位的需求。所以这里我们介绍的工具相对多一些、丰富一些。

**JDK 自带的工具**

- jconsole：JDK 自带的可视化监控工具。查看 Java 应用程序的运行概况、监控堆信息、永久区（或元空间）使用情况、类加载情况等
- Visual VM：Visual VM 是一个工具，它提供了一个可视界面，用于查看 Java 虚拟机上运行的基于 Java 技术的应用程序的详细信息。
- JMC：Java Mission Control，内置 Java Flight Recorder。能够以极低的性能开销收集 Java 虚拟机的性能数据。

**第三方工具**

- MAT：MAT（Memory Analyzer Tool）是基于 Eclipse 的内存分析工具，是一个快速、功能丰富的 Java heap 分析工具，它可以帮助我们查找内存泄漏和减少内存消耗
- JProfiler：商业软件，需要付费。功能强大。

## 3.2. JConsole

jconsole：从 Java5 开始，在 JDK 中自带的 java 监控和管理控制台。用于对 JVM 中内存、线程和类等的监控，是一个基于 JMX（java management extensions）的 GUI 性能监控工具。

官方地址：[https://docs.oracle.com/javase/7/docs/technotes/guides/management/jconsole.html](https://docs.oracle.com/javase/7/docs/technotes/guides/management/jconsole.html)

![image-20210505141631635](https://img-blog.csdnimg.cn/img_convert/2a3da9e0684da25f3603859309a31002.png)

![image-20210505141726143](https://img-blog.csdnimg.cn/img_convert/01d1c91e8a41137321af9334a383eeda.png)

![image-20210505141924211](https://img-blog.csdnimg.cn/img_convert/fd74276fd1dd7e4542994d1da5768bff.png)

![image-20210505141950000](https://img-blog.csdnimg.cn/img_convert/c590dbcfb21edbf73f9b7a4d4e342cb7.png)

![image-20210505142050157](https://img-blog.csdnimg.cn/img_convert/0394d3dec7f075f88d1321565e4b0c40.png)

## 3.3. Visual VM

Visual VM 是一个功能强大的多合一故障诊断和性能监控的可视化工具。它集成了多个 JDK 命令行工具，使用 Visual VM 可用于显示虚拟机进程及进程的配置和环境信息（jps，jinfo），监视应用程序的 CPU、GC、堆、方法区及线程的信息（jstat、jstack）等，甚至代替 JConsole。在 JDK 6 Update 7 以后，Visual VM 便作为 JDK 的一部分发布（VisualVM 在 JDK／bin 目录下）即：它完全免费。

**主要功能：**

- 1.生成/读取堆内存/线程快照
- 2.查看 JVM 参数和系统属性
- 3.查看运行中的虚拟机进程
- 4.程序资源的实时监控
- 5.JMX 代理连接、远程环境监控、CPU 分析和内存分析

官方地址：[https://visualvm.github.io/index.html](https://visualvm.github.io/index.html)

![image-20210505143844282](https://img-blog.csdnimg.cn/img_convert/5778843e25883aed6ee8591e7f57465a.png)

![image-20210505144716064](https://img-blog.csdnimg.cn/img_convert/750e766290dd3ce1c31bece436870f96.png)

![image-20210505144805307](https://img-blog.csdnimg.cn/img_convert/43a8b0745532825ab4a262a953aa5ffd.png)

## 3.4. Eclipse MAT

MAT（Memory Analyzer Tool）工具是一款功能强大的 Java 堆内存分析器。可以用于查找内存泄漏以及查看内存消耗情况。MAT 是基于 Eclipse 开发的，不仅可以单独使用，还可以作为插件的形式嵌入在 Eclipse 中使用。是一款免费的性能分析工具，使用起来非常方便。

MAT 可以分析 heap dump 文件。在进行内存分析时，只要获得了反映当前设备内存映像的 hprof 文件，通过 MAT 打开就可以直观地看到当前的内存信息。一般说来，这些内存信息包含：

- 所有的对象信息，包括对象实例、成员变量、存储于栈中的基本类型值和存储于堆中的其他对象的引用值。
- 所有的类信息，包括 classloader、类名称、父类、静态变量等
- GCRoot 到所有的这些对象的引用路径
- 线程信息，包括线程的调用栈及此线程的线程局部变量（TLS）

MAT 不是一个万能工具，它并不能处理所有类型的堆存储文件。但是比较主流的厂家和格式，例如 Sun，HP，SAP 所采用的 HPROF 二进制堆存储文件，以及 IBM 的 PHD 堆存储文件等都能被很好的解析。

最吸引人的还是能够快速为开发人员生成内存泄漏报表，方便定位问题和分析问题。虽然 MAT 有如此强大的功能，但是内存分析也没有简单到一键完成的程度，很多内存问题还是需要我们从 MAT 展现给我们的信息当中通过经验和直觉来判断才能发现。

官方地址： [https://www.eclipse.org/mat/downloads.php](https://www.eclipse.org/mat/downloads.php)

![image-20210505145708567](https://img-blog.csdnimg.cn/img_convert/23d0ea8c73c4e7fb57f47fba7ee39f3f.png)

![image-20210505145826442](https://img-blog.csdnimg.cn/img_convert/e5dad78d08ba1aee3a9583c33d83c53f.png)

![image-20210505145945951](https://img-blog.csdnimg.cn/img_convert/b25b5cb539c1d5622f4855dffb1fd21e.png)

![image-20210505150039376](https://img-blog.csdnimg.cn/img_convert/0e41893c02f420e50d36c59acf3021b6.png)

## 3.5. JProfiler

在运行 Java 的时候有时候想测试运行时占用内存情况，这时候就需要使用测试工具查看了。在 eclipse 里面有 Eclipse Memory Analyzer tool（MAT）插件可以测试，而在 IDEA 中也有这么一个插件，就是 JProfiler。JProfiler 是由 ej-technologies 公司开发的一款 Java 应用性能诊断工具。功能强大，但是收费。

**特点：**

- 使用方便、界面操作友好（简单且强大）
- 对被分析的应用影响小（提供模板）
- CPU，Thread，Memory 分析功能尤其强大
- 支持对 jdbc，noSql，jsp，servlet，socket 等进行分析
- 支持多种模式（离线，在线）的分析
- 支持监控本地、远程的 JVM
- 跨平台，拥有多种操作系统的安装版本

**主要功能：**

- 1-方法调用：对方法调用的分析可以帮助您了解应用程序正在做什么，并找到提高其性能的方法
- 2-内存分配：通过分析堆上对象、引用链和垃圾收集能帮您修复内存泄露问题，优化内存使用
- 3-线程和锁：JProfiler 提供多种针对线程和锁的分析视图助您发现多线程问题
- 4-高级子系统：许多性能问题都发生在更高的语义级别上。例如，对于 JDBC 调用，您可能希望找出执行最慢的 SQL 语句。JProfiler 支持对这些子系统进行集成分析

官网地址：[https://www.ej-technologies.com/products/jprofiler/overview.html](https://www.ej-technologies.com/products/jprofiler/overview.html)

**数据采集方式：**

JProfier 数据采集方式分为两种：Sampling（样本采集）和 Instrumentation（重构模式）

**Instrumentation**：这是 JProfiler 全功能模式。在 class 加载之前，JProfier 把相关功能代码写入到需要分析的 class 的 bytecode 中，对正在运行的 jvm 有一定影响。

- 优点：功能强大。在此设置中，调用堆栈信息是准确的。
- 缺点：若要分析的 class 较多，则对应用的性能影响较大，CPU 开销可能很高（取决于 Filter 的控制）。因此使用此模式一般配合 Filter 使用，只对特定的类或包进行分析

**Sampling**：类似于样本统计，每隔一定时间（5ms）将每个线程栈中方法栈中的信息统计出来。

- 优点：对 CPU 的开销非常低，对应用影响小（即使你不配置任何 Filter）
- 缺点：一些数据／特性不能提供（例如：方法的调用次数、执行时间）

注：JProfiler 本身没有指出数据的采集类型，这里的采集类型是针对方法调用的采集类型。因为 JProfiler 的绝大多数核心功能都依赖方法调用采集的数据，所以可以直接认为是 JProfiler 的数据采集类型。

**遥感监测 Telemetries**

![image-20210505164521410](https://img-blog.csdnimg.cn/img_convert/b385d959623a0684d1a40700f4bc1243.png)

![image-20210505164907312](https://img-blog.csdnimg.cn/img_convert/aa57ab4a3183801e003546c177ab64ee.png)

![image-20210505164815324](https://img-blog.csdnimg.cn/img_convert/75200c0d6aeaaade33422d40bd64beb3.png)

![image-20210505164945192](https://img-blog.csdnimg.cn/img_convert/6342c78f10e0c8d96243ae69c280c742.png)

![image-20210505165010529](https://img-blog.csdnimg.cn/img_convert/eda04270592f6cf5cc53f6300f9f084a.png)

![image-20210505165128212](https://img-blog.csdnimg.cn/img_convert/944971c96b35f20aa4073a39ee8f678e.png)

![image-20210505165249919](https://img-blog.csdnimg.cn/img_convert/983f44592d93befafdb1818ea9fb7603.png)

**内存视图 Live Memory**

Live memory 内存剖析：class／class instance 的相关信息。例如对象的个数，大小，对象创建的方法执行栈，对象创建的热点。

- **所有对象 All Objects**：显示所有加载的类的列表和在堆上分配的实例数。只有 Java 1.5（JVMTI）才会显示此视图。
- **记录对象 Record Objects**：查看特定时间段对象的分配，并记录分配的调用堆栈。
- **分配访问树 Allocation Call Tree**：显示一棵请求树或者方法、类、包或对已选择类有带注释的分配信息的 J2EE 组件。
- **分配热点 Allocation Hot Spots**：显示一个列表，包括方法、类、包或分配已选类的 J2EE 组件。你可以标注当前值并且显示差异值。对于每个热点都可以显示它的跟踪记录树。
- **类追踪器 Class Tracker**：类跟踪视图可以包含任意数量的图表，显示选定的类和包的实例与时间。

![image-20210505164554298](https://img-blog.csdnimg.cn/img_convert/49b08570bc68a4ccb1b76c610001160e.png)

![image-20210505165519790](https://img-blog.csdnimg.cn/img_convert/12e4a0779da98da28310602aa727fe77.png)

**堆遍历 heap walker**

![image-20210505165710620](https://img-blog.csdnimg.cn/img_convert/ffb0632996afc5ab68554c918c6ba5c5.png)

![image-20210505165823201](https://img-blog.csdnimg.cn/img_convert/9328465f8078d485d713866676fedddd.png)

**cpu 视图 cpu views**

JProfiler 提供不同的方法来记录访问树以优化性能和细节。线程或者线程组以及线程状况可以被所有的视图选择。所有的视图都可以聚集到方法、类、包或 J2EE 组件等不同层上。

- **访问树 Call Tree**：显示一个积累的自顶向下的树，树中包含所有在 JVM 中已记录的访问队列。JDBC，JMS 和 JNDI 服务请求都被注释在请求树中。请求树可以根据 Servlet 和 JSP 对 URL 的不同需要进行拆分。
- **热点 Hot Spots**：显示消耗时间最多的方法的列表。对每个热点都能够显示回溯树。该热点可以按照方法请求，JDBC，JMS 和 JNDI 服务请求以及按照 URL 请求来进行计算。
- **访问图 Call Graph**：显示一个从已选方法、类、包或 J2EE 组件开始的访问队列的图。
- **方法统计 Method Statistis**：显示一段时间内记录的方法的调用时间细节。

![image-20210505170055722](https://img-blog.csdnimg.cn/img_convert/2d40f4905776b879b96ea26323b5437e.png)

![image-20210505170141278](https://img-blog.csdnimg.cn/img_convert/054ba6962384453984936f4dc2fe5f64.png)

**线程视图 threads**

JProfiler 通过对线程历史的监控判断其运行状态，并监控是否有线程阻塞产生，还能将一个线程所管理的方法以树状形式呈现。对线程剖析。

- **线程历史 Thread History**：显示一个与线程活动和线程状态在一起的活动时间表。
- **线程监控 Thread Monitor**：显示一个列表，包括所有的活动线程以及它们目前的活动状况。
- **线程转储 Thread Dumps**：显示所有线程的堆栈跟踪。

线程分析主要关心三个方面：

- 1．web 容器的线程最大数。比如：Tomcat 的线程容量应该略大于最大并发数。
- 2．线程阻塞
- 3．线程死锁

![image-20210505170739972](https://img-blog.csdnimg.cn/img_convert/18074c3907f5b0b197cd88802897a758.png)

**监控和锁 Monitors ＆Locks**

所有线程持有锁的情况以及锁的信息。观察 JVM 的内部线程并查看状态：

- **死锁探测图表 Current Locking Graph**：显示 JVM 中的当前死锁图表。
- **目前使用的监测器 Current Monitors**：显示目前使用的监测器并且包括它们的关联线程。
- **锁定历史图表 Locking History Graph**：显示记录在 JVM 中的锁定历史。
- **历史检测记录 Monitor History**：显示重大的等待事件和阻塞事件的历史记录。
- **监控器使用统计 Monitor Usage Statistics**：显示分组监测，线程和监测类的统计监测数据

## 3.6. Arthas

上述工具都必须在服务端项目进程中配置相关的监控参数，然后工具通过远程连接到项目进程，获取相关的数据。这样就会带来一些不便，比如线上环境的网络是隔离的，本地的监控工具根本连不上线上环境。并且类似于 Jprofiler 这样的商业工具，是需要付费的。

那么有没有一款工具不需要远程连接，也不需要配置监控参数，同时也提供了丰富的性能监控数据呢？

阿里巴巴开源的性能分析神器 Arthas 应运而生。

Arthas 是 Alibaba 开源的 Java 诊断工具，深受开发者喜爱。在线排查问题，无需重启；动态跟踪 Java 代码；实时监控 JVM 状态。Arthas 支持 JDK 6 ＋，支持 Linux／Mac／Windows，采用命令行交互模式，同时提供丰富的 Tab 自动补全功能，进一步方便进行问题的定位和诊断。当你遇到以下类似问题而束手无策时，Arthas 可以帮助你解决：

- 这个类从哪个 jar 包加载的？为什么会报各种类相关的 Exception？
- 我改的代码为什么没有执行到？难道是我没 commit？分支搞错了？
- 遇到问题无法在线上 debug，难道只能通过加日志再重新发布吗？
- 线上遇到某个用户的数据处理有问题，但线上同样无法 debug，线下无法重现！
- 是否有一个全局视角来查看系统的运行状况？
- 有什么办法可以监控到 JVM 的实时运行状态？
- 怎么快速定位应用的热点，生成火焰图？

官方地址：[https://arthas.aliyun.com/doc/quick-start.html](https://arthas.aliyun.com/doc/quick-start.html)

安装方式：如果速度较慢，可以尝试国内的码云 Gitee 下载。

```shell
wget https://io/arthas/arthas-boot.jar
wget https://arthas/gitee/io/arthas-boot.jar
```

Arthas 只是一个 java 程序，所以可以直接用 java -jar 运行。

除了在命令行查看外，Arthas 目前还支持 Web Console。在成功启动连接进程之后就已经自动启动,可以直接访问 http://127.0.0.1:8563/ 访问，页面上的操作模式和控制台完全一样。

**基础指令**

```shell
quit/exit 退出当前 Arthas客户端，其他 Arthas喜户端不受影响
stop/shutdown 关闭 Arthas服务端，所有 Arthas客户端全部退出
help 查看命令帮助信息
cat 打印文件内容，和linux里的cat命令类似
echo 打印参数，和linux里的echo命令类似
grep 匹配查找，和linux里的gep命令类似
tee 复制标隹输入到标准输出和指定的文件，和linux里的tee命令类似
pwd 返回当前的工作目录，和linux命令类似
cls 清空当前屏幕区域
session 查看当前会话的信息
reset 重置增强类，将被 Arthas增强过的类全部还原, Arthas服务端关闭时会重置所有增强过的类
version 输出当前目标Java进程所加载的 Arthas版本号
history 打印命令历史
keymap Arthas快捷键列表及自定义快捷键
```

**jvm 相关**

```shell
dashboard 当前系统的实时数据面板
thread 查看当前JVM的线程堆栈信息
jvm 查看当前JVM的信息
sysprop 查看和修改JVM的系统属性
sysem 查看JVM的环境变量
vmoption 查看和修改JVM里诊断相关的option
perfcounter 查看当前JVM的 Perf Counter信息
logger 查看和修改logger
getstatic 查看类的静态属性
ognl 执行ognl表达式
mbean 查看 Mbean的信息
heapdump dump java heap，类似jmap命令的 heap dump功能
```

**class/classloader 相关**

```shell
sc 查看JVM已加载的类信息
	-d 输出当前类的详细信息，包括这个类所加载的原始文件来源、类的声明、加载的Classloader等详细信息。如果一个类被多个Classloader所加载，则会出现多次
	-E 开启正则表达式匹配，默认为通配符匹配
	-f 输出当前类的成员变量信息（需要配合参数-d一起使用）
	-X 指定输出静态变量时属性的遍历深度，默认为0，即直接使用toString输出
sm 查看已加载类的方法信息
	-d 展示每个方法的详细信息
	-E 开启正则表达式匹配,默认为通配符匹配
jad 反编译指定已加载类的源码
mc 内存编译器，内存编译.java文件为.class文件
retransform 加载外部的.class文件, retransform到JVM里
redefine 加载外部的.class文件，redefine到JVM里
dump dump已加载类的byte code到特定目录
classloader 查看classloader的继承树，urts，类加载信息，使用classloader去getResource
	-t 查看classloader的继承树
	-l 按类加载实例查看统计信息
	-c 用classloader对应的hashcode来查看对应的 Jar urls
```

**monitor/watch/trace 相关**

```
monitor 方法执行监控，调用次数、执行时间、失败率
	-c 统计周期，默认值为120秒
watch 方法执行观测，能观察到的范围为：返回值、抛出异常、入参，通过编写groovy表达式进行对应变量的查看
	-b 在方法调用之前观察(默认关闭)
	-e 在方法异常之后观察(默认关闭)
	-s 在方法返回之后观察(默认关闭)
	-f 在方法结束之后(正常返回和异常返回)观察(默认开启)
	-x 指定输岀结果的属性遍历深度,默认为0
trace 方法内部调用路径,并输出方法路径上的每个节点上耗时
	-n 执行次数限制
stack 输出当前方法被调用的调用路径
tt 方法执行数据的时空隧道,记录下指定方法每次调用的入参和返回信息,并能对这些不同的时间下调用进行观测
```

**其他**

```shell
jobs 列出所有job
kill 强制终止任务
fg 将暂停的任务拉到前台执行
bg 将暂停的任务放到后台执行
grep 搜索满足条件的结果
plaintext 将命令的结果去除ANSI颜色
wc 按行统计输出结果
options 查看或设置Arthas全局开关
profiler 使用async-profiler对应用采样，生成火焰图
```

## 3.7. Java Misssion Control

在 Oracle 收购 Sun 之前，Oracle 的 JRockit 虚拟机提供了一款叫做 JRockit Mission Control 的虚拟机诊断工具。

在 Oracle 收购 sun 之后，Oracle 公司同时拥有了 Hotspot 和 JRockit 两款虚拟机。根据 Oracle 对于 Java 的战略，在今后的发展中，会将 JRokit 的优秀特性移植到 Hotspot 上。其中一个重要的改进就是在 Sun 的 JDK 中加入了 JRockit 的支持。

在 Oracle JDK 7u40 之后，Mission Control 这款工具己经绑定在 Oracle JDK 中发布。

自 Java11 开始，本节介绍的 JFR 己经开源。但在之前的 Java 版本，JFR 属于 Commercial Feature 通过 Java 虚拟机参数-XX:+UnlockCommercialFeatures 开启。

Java Mission Control（简称 JMC) ， Java 官方提供的性能强劲的工具，是一个用于对 Java 应用程序进行管理、监视、概要分析和故障排除的工具套件。它包含一个 GUI 客户端以及众多用来收集 Java 虚拟机性能数据的插件如 JMX Console（能够访问用来存放虚拟机齐个于系统运行数据的 MXBeans）以及虚拟机内置的高效 profiling 工具 Java Flight Recorder（JFR）。

JMC 的另一个优点就是：采用取样，而不是传统的代码植入技术，对应用性能的影响非常非常小，完全可以开着 JMC 来做压测（唯一影响可能是 full gc 多了）。

官方地址：[https://github.com/JDKMissionControl/jmc](https://github.com/JDKMissionControl/jmc)

![image-20210505184358041](https://img-blog.csdnimg.cn/img_convert/042f2d109ebcf51894f822706963e399.png)

**Java Flight Recorder**

Java Flight Recorder 是 JMC 的其中一个组件，能够以极低的性能开销收集 Java 虚拟机的性能数据。与其他工具相比，JFR 的性能开销很小，在默认配置下平均低于 1%。JFR 能够直接访问虚拟机内的敌据并且不会影响虚拟机的优化。因此它非常适用于生产环境下满负荷运行的 Java 程序。

Java Flight Recorder 和 JDK Mission Control 共同创建了一个完整的工具链。JDK Mission Control 可对 Java Flight Recorder 连续收集低水平和详细的运行时信息进行高效、详细的分析。

当启用时 JFR 将记录运行过程中发生的一系列事件。其中包括 Java 层面的事件如线程事件、锁事件，以及 Java 虚拟机内部的事件，如新建对象，垃圾回收和即时编译事件。按照发生时机以及持续时间来划分，JFR 的事件共有四种类型，它们分别为以下四种：

- 瞬时事件（Instant Event) ，用户关心的是它们发生与否，例如异常、线程启动事件。
- 持续事件(Duration Event) ，用户关心的是它们的持续时间，例如垃圾回收事件。
- 计时事件(Timed Event) ，是时长超出指定阈值的持续事件。
- 取样事件（Sample Event)，是周期性取样的事件。

取样事件的其中一个常见例子便是方法抽样（Method Sampling），即每隔一段时问统计各个线程的栈轨迹。如果在这些抽样取得的栈轨迹中存在一个反复出现的方法，那么我们可以推测该方法是热点方法

![image-20210505185941373](https://img-blog.csdnimg.cn/img_convert/d96c890e6187bcfa8d4a558be64354e6.png)

![image-20210505185954567](https://img-blog.csdnimg.cn/img_convert/dbaae7f62c614ef03aebb267b4249650.png)

![image-20210505190009274](https://img-blog.csdnimg.cn/img_convert/a0bc985fd0274fc17c9dc2e8e205a8a2.png)

![image-20210505190023099](https://img-blog.csdnimg.cn/img_convert/fe38780df6ccf1c3f3206baaa089ff1a.png)

![image-20210505190037354](https://img-blog.csdnimg.cn/img_convert/0e8ab54b4fdc5cd2f4d7e1cda87dfe52.png)

![image-20210505190052561](https://img-blog.csdnimg.cn/img_convert/ef07d257c25f15fe7d6bfdbe6ee0f087.png)

![image-20210505190106004](https://img-blog.csdnimg.cn/img_convert/3f65159c21e0c6996588c90c7c5ca8e6.png)

## 3.8. 其他工具

**Flame Graphs（火焰图）**

在追求极致性能的场景下，了解你的程序运行过程中 cpu 在干什么很重要，火焰图就是一种非常直观的展示 CPU 在程序整个生命周期过程中时间分配的工具。火焰图对于现代的程序员不应该陌生，这个工具可以非常直观的显示出调用找中的 CPU 消耗瓶颈。

网上的关于 Java 火焰图的讲解大部分来自于 Brenden Gregg 的博客 [http://new.brendangregg.com/flamegraphs.html ](http://new.brendangregg.com/flamegraphs.html)

![image-20210505190823214](https://img-blog.csdnimg.cn/img_convert/c2692cea072a29b00b420933892ae9f9.png)

火焰图，简单通过 x 轴横条宽度来度量时间指标，y 轴代表线程栈的层次。

**Tprofiler**

案例： 使用 JDK 自身提供的工具进行 JVM 调优可以将下 TPS 由 2.5 提升到 20（提升了 7 倍），并准确 定位系统瓶颈。

系统瓶颈有：应用里释态对象不是太多、有大量的业务线程在频繁创建一些生命周期很长的临时对象，代码里有问题。

那么，如何在海量业务代码里边准确定位这些性能代码？这里使用阿里开源工具 Tprofiler 来定位 这些性能代码，成功解决掉了 GC 过于频繁的性能瓶预，并最终在上次优化的基础上将 TPS 再提升了 4 倍，即提升到 100。

- Tprofiler 配置部署、远程操作、 日志阅谈都不太复杂，操作还是很简单的。但是其却是能够 起到一针见血、立竿见影的效果，帮我们解决了 GC 过于频繁的性能瓶预。
- Tprofiler 最重要的特性就是能够统汁出你指定时间段内 JVM 的 top method 这些 top method 极有可能就是造成你 JVM 性能瓶颈的元凶。这是其他大多数 JVM 调优工具所不具备的，包括 JRockit Mission Control。JRokit 首席开发者 Marcus Hirt 在其私人博客《 Lom Overhead Method Profiling cith Java Mission Control》下的评论中曾明确指出 JRMC 井不支持 TOP 方法的统计。

官方地址：[http://github.com/alibaba/Tprofiler](http://github.com/alibaba/Tprofiler)

**Btrace**

常见的动态追踪工具有 BTrace、HouseHD（该项目己经停止开发）、Greys-Anatomy（国人开发 个人开发者）、Byteman（JBoss 出品），注意 Java 运行时追踪工具井不限干这几种，但是这几个是相对比较常用的。

BTrace 是 SUN Kenai 云计算开发平台下的一个开源项目，旨在为 java 提供安全可靠的动态跟踪分析工具。先看一卜日 Trace 的官方定义：

![image-20210505192042974](https://img-blog.csdnimg.cn/img_convert/8df058bdfb18387a90cd5dd87a2a2f04.png)

大概意思是一个 Java 平台的安全的动态追踪工具，可以用来动态地追踪一个运行的 Java 程序。BTrace 动态调整目标应用程序的类以注入跟踪代码（“字节码跟踪“）。

**YourKit**

**JProbe**

**Spring Insight**

<hr/>