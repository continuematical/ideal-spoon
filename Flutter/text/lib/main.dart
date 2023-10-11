import 'package:flutter/material.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
        title: 'wanAndroid',
        theme: ThemeData(primarySwatch: Colors.blue),
        home: const ScaffoldRoutine());
  }
}

class ScaffoldRoutine extends StatefulWidget {
  const ScaffoldRoutine({super.key});

  @override
  State<StatefulWidget> createState() => _ScaffoldRoutineState();
}

class _ScaffoldRoutineState extends State<ScaffoldRoutine> {
  final ScrollController _controller = ScrollController();
  bool isShowToTop = false;
  List<Icon> icons = [];

  @override
  void initState() {
    // TODO: implement initState
    super.initState();
    //置顶
    _controller.addListener(() {
      if (_controller.offset < 100 && isShowToTop) {
        setState(() {
          isShowToTop = false;
        });
      } else if (_controller.offset >= 100 && isShowToTop == false) {
        setState(() {
          isShowToTop = true;
        });
      }
    });
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: Scrollbar(
          child: NotificationListener<ScrollNotification>(
        onNotification: (ScrollNotification notification) {
          double progress = notification.metrics.pixels /
              notification.metrics.maxScrollExtent;
          //重新构建
          setState(() {});
          return false;
        },
        child: const GridViewRoute1(),
      )),
      bottomNavigationBar: BottomNavigationBar(
        items: const [
          BottomNavigationBarItem(icon: Icon(Icons.home), label: "home"),
          BottomNavigationBarItem(
              icon: Icon(Icons.business), label: "business"),
          BottomNavigationBarItem(icon: Icon(Icons.school), label: "school"),
        ],
      ),
      drawer: const MyDrawer(),
      appBar: AppBar(
        title: const Text("App Name"),
        centerTitle: true,
        actions: [
          IconButton(
            icon: const Icon(Icons.add),
            onPressed: () {},
          ),
        ],
        leading: Builder(
          builder: (context) {
            return IconButton(
              onPressed: () {
                Scaffold.of(context).openDrawer(); //打开抽屉菜单
              },
              icon: const Icon(
                Icons.dashboard,
                color: Colors.white,
              ),
            );
          },
        ),
      ),
      floatingActionButton: !isShowToTop
          ? null
          : FloatingActionButton(
              child: const Icon(Icons.arrow_upward),
              onPressed: () {
                //按下时执行动画
                _controller.animateTo(0,
                    duration: const Duration(milliseconds: 200),
                    curve: Curves.ease);
              }),
    );
  }

  //模拟异步获取数据
  void _retrieveIcons() {
    Future.delayed(const Duration(seconds: 2)).then((values) {
      setState(() {
        icons.addAll([
          const Icon(Icons.aspect_ratio),
          const Icon(Icons.add_alert_rounded),
          const Icon(Icons.confirmation_num_sharp),
        ]);
      });
    });
  }
}

class GridViewRoute1 extends StatefulWidget {
  const GridViewRoute1({super.key});

  @override
  State<StatefulWidget> createState() => _GridViewRouteState1();
}

class _GridViewRouteState1 extends State<GridViewRoute1> {
  @override
  Widget build(BuildContext context) {
    return GridView(
      gridDelegate: const SliverGridDelegateWithFixedCrossAxisCount(
        crossAxisCount: 3,
        childAspectRatio: 1.0,
      ),
      children: const [
        Icon(Icons.add),
        Icon(Icons.add_a_photo_outlined),
        Icon(Icons.add_alarm_rounded),
        Icon(Icons.add_alert),
      ],
    );
  }
}

class MyDrawer extends StatelessWidget {
  const MyDrawer({super.key});

  @override
  Widget build(BuildContext context) {
    return Drawer(
      child: MediaQuery.removePadding(
          context: context,
          removeTop: true,
          child: Column(
            crossAxisAlignment: CrossAxisAlignment.start,
            children: [
              Padding(
                padding: const EdgeInsets.only(top: 38.0),
                child: Row(
                  children: const [
                    Padding(
                      padding: EdgeInsets.symmetric(horizontal: 16.0),
                      child: Icon(
                        Icons.perm_contact_cal_rounded,
                      ),
                    ),
                    Text(
                      "hello world",
                      style: TextStyle(fontWeight: FontWeight.bold),
                    )
                  ],
                ),
              ),
              Expanded(
                  child: ListView(
                children: const [
                  ListTile(
                    leading: Icon(Icons.add),
                    title: Text("add account"),
                  ),
                  ListTile(
                    leading: Icon(Icons.settings),
                    title: Text("manage accounts"),
                  )
                ],
              ))
            ],
          )),
    );
  }
}

class AnimatedListRoutine extends StatefulWidget {
  const AnimatedListRoutine({super.key});

  @override
  createState() => _AnimatedListRoutine();
}

class _AnimatedListRoutine extends State<AnimatedListRoutine> {
  int count = 5;
  var data = <String>[];
  final globalKey = GlobalKey<AnimatedListState>();

  @override
  void initState() {
    for (int i = 0; i < count; i++) {
      data.add("${i + 1}");
    }
    super.initState();
  }

  @override
  Widget build(BuildContext context) {
    return Stack(
      children: [
        AnimatedList(
          itemBuilder:
              (BuildContext context, int index, Animation<double> animation) {
            return FadeTransition(
              opacity: animation,
              child: buildItem(context, index),
            );
          },
          initialItemCount: data.length,
          key: globalKey,
        )
      ],
    );
  }

  Widget buildItem(context, index) {
    String value = data[index];
    return ListTile(
        key: ValueKey(value), //唯一值，可以作为key
        title: Text(value),
        trailing: IconButton(
          onPressed: () {
            onDelete(context, index);
          },
          icon: const Icon(Icons.delete),
        ));
  }

  void onDelete(context, index) {
    setState(() {
      globalKey.currentState!.removeItem(index, (context, animation) {
        var item = buildItem(context, index);
        data.remove(index);
        return FadeTransition(
          opacity: CurvedAnimation(
            parent: animation,
            curve: const Interval(0.5, 1.0),
          ),
          //不断减小列表项的高度
          child: SizeTransition(
            sizeFactor: animation,
            axisAlignment: 0.0,
            child: item,
          ),
        );
      });
    });
  }
}
