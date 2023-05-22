import 'dart:async';

import 'package:flutter/material.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  // This widget is the root of your application.
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Flutter Demo',
      theme: ThemeData(
        primarySwatch: Colors.blue,
      ),
      home: const MyHomePage(title: 'Flutter Demo Home Page'),
    );
  }
}

class MyHomePage extends StatefulWidget {
  const MyHomePage({super.key, required this.title});

  final String title;

  @override
  State<MyHomePage> createState() => _MyHomePageState();
}

class _MyHomePageState extends State<MyHomePage>
    with SingleTickerProviderStateMixin {
  int _counter = 0;
  final duration = const Duration(milliseconds: 300);
  late Timer timer;
  late AnimationController scoreAnimationController =
      AnimationController(vsync: this, duration: const Duration(seconds: 300));
  var scorePosition = 0.0;
  var scoreOpacity = 0.0;

  @override
  void initState() {
    // TODO: implement initState
    super.initState();
    scoreAnimationController.addListener(() {
      setState(() {
        scorePosition = scoreAnimationController.value * 100;
        scoreOpacity = scoreAnimationController.value;
      });
    });
  }

  void onTapUp(TapUpDetails tap) {
    timer.cancel();
  }

  void onTapDown(TapDownDetails tap) {
    scoreAnimationController.forward(from: 0.0);
    timer = Timer.periodic(duration, _incrementCounter);
    _incrementCounter(timer);
  }

  void _incrementCounter(Timer timer) {
    setState(() {
      _counter++;
    });
  }

  Widget getScoreButton() {
    return Positioned(
      bottom: scorePosition,
      child: Opacity(
        opacity: scoreOpacity,
        child: Container(
          height: 50.0,
          width: 50.0,
          alignment: FractionalOffset.bottomLeft,
          decoration: const ShapeDecoration(
            shape: CircleBorder(
              side: BorderSide.none,
            ),
            color: Colors.pink,
          ),
          child: Center(
            child: Text(
              "+$_counter",
              style: const TextStyle(
                  color: Colors.white,
                  fontWeight: FontWeight.bold,
                  fontSize: 20.0),
            ),
          ),
        ),
      ),
    );
  }

  Widget getClapButton() {
    return GestureDetector(
      onTapUp: onTapUp,
      onTapDown: onTapDown,
      child: Container(
        height: 60.0,
        width: 60.0,
        padding: const EdgeInsets.all(10.0),
        decoration: BoxDecoration(
            border: Border.all(
              color: Colors.pink,
              width: 1.0,
            ),
            borderRadius: BorderRadius.circular(50.0),
            color: Colors.white,
            boxShadow: const [BoxShadow(color: Colors.pink, blurRadius: 1.0)]),
        child: const Icon(
          Icons.add,
          color: Colors.pink,
          size: 40.0,
        ),
      ),
    );
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text(widget.title),
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: <Widget>[
            const Text(
              'You have pushed the button this many times:',
            ),
            Text(
              '$_counter',
              style: Theme.of(context).textTheme.headlineMedium,
            ),
          ],
        ),
      ),
      floatingActionButton: Padding(
          padding: const EdgeInsets.only(right: 20.0),
          child: Stack(
            alignment: FractionalOffset.bottomRight,
            children: <Widget>[
              getScoreButton(),
              getClapButton(),
            ],
          )),
    );
  }
}
