# State
`Jetpack Compose` 需要用`state` 进行驱动`UI` 更新，相当于`Flutter` 的`StatefulWidget` 。
重组：重新执行`@Composable`函数来更新UI的过程被称为重组，而这正是由于`Composable`的状态变化所触发的。
## mutableStateOf
例子：
```kotlin
@Composable
fun Greeting() {
    var countNumber by remember {
        mutableStateOf(0)   //1
    }

    Column {
        Text(text = "当前计数: $countNumber")   //重组刷新计数

        Button(onClick = { countNumber++ }) {  //增加以修改数值
            Text(text = "增加计数")
        }
    }

}
```
进入`mutableStateOf` 中：
```kotlin
fun <T> mutableStateOf(  
    value: T,  
    policy: SnapshotMutationPolicy<T> = structuralEqualityPolicy()  
): MutableState<T> = createSnapshotMutableState(value, policy)
```
快照系统会把所有订阅了`State`的`RecomposeScope`记录下来，当`State`的值`value`发生变化时，会通知所有的`RecomposeScope`进行重组。
创建`mutableStateOf` 的方式
```kotlin
//返回T类型的value
var countNumber = remember {
    mutableStateOf(0)
}

//通过解构返回T类型的value以及(T)→Unit类型的set方法
var (countNumber,setCountNumber) = remember {
    mutableStateOf(0)
}

//使用属性代理。
//对countNumber的读写会通过getValue和setValue这两个运算符的
//重写最终代理为对value的操作，通过by关键字，可以像访问一个普通的Int变量一样对状态进行读写。
var countNumber by remember {
    mutableStateOf(0)
}

//委托给了下面二个函数
@Suppress("NOTHING_TO_INLINE")
inline operator fun <T> State<T>.getValue(thisObj: Any?, property: KProperty<*>): T = value

@Suppress("NOTHING_TO_INLINE")
inline operator fun <T> MutableState<T>.setValue(thisObj: Any?, property: KProperty<*>, value: T) {
    this.value = value
}
```
当使用`by`代理创建`State`时，需要额外引入以下扩展方法：
```kotlin
import androidx.compose.runtime.getValue
import androidx.compose.runtime.setValue
```
## remember
```kotlin
inline fun <T> remember(calculation: @DisallowComposableCalls () -> T): T =  
    currentComposer.cache(false, calculation)
```
```kotlin
@ComposeCompilerApi
inline fun <T> Composer.cache(invalid: Boolean, block: @DisallowComposableCalls () -> T): T {
    @Suppress("UNCHECKED_CAST")
    return rememberedValue().let {
        if (invalid || it === Composer.Empty) {
            val value = block()      //对mutableStateOf的调用获取新的值
            updateRememberedValue(value)   //记录新的值做缓存
            value
        } else it
    } as T
}
```
总结：
_**mutableStateOf创建可变状态变量**_。`mutableStateOf` 函数用于创建可变状态`（mutable state）`。它接受一个初始值作为参数，并返回一个包含此值的可变状态变量。可变状态变量的值可以更改，在 `Compose` 中需要在 `Composable` 函数内部使用。

_**remember记录可变状态变量并保证使用时的统一和重建时状态的恢复**_。`remember` 函数用于将值保留在 `Composable` 函数内。它可以用来在 `Composable` 函数的多次调用之间保留不变的值，以避免因组件重组而导致的数据混乱和丢失。`remember` 函数接受一个 `lambda` 表达式作为参数，这个 `lambda` 表达式通常包含对 `mutableStateOf` 的调用，用于创建和保留一个可变状态的变量。

