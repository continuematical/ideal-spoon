import 'package:flutter/material.dart';
import 'package:flutter/physics.dart';

void main() {
  runApp(const MaterialApp(
    home: PhysicsCardDragDemo(),
  ));
}

class PhysicsCardDragDemo extends StatelessWidget {
  const PhysicsCardDragDemo({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(),
      body: DraggableCard(
        child: const Icon(Icons.add_alert_rounded),
      ),
    );
  }
}

class DraggableCard extends StatefulWidget {
  late Widget child;

  DraggableCard({
    super.key,
    required this.child,
  });

  @override
  State<StatefulWidget> createState() => _CreateDraggableCard();
}

///SingleTickerProviderStateMixin是用来在StatefulWidget中管理单个AnimationController
///的Mixin；它提供了一个TickerProvider，用于将AnimationController与TickerProviderStateMixin一起使用。

class _CreateDraggableCard extends State<DraggableCard>
    with SingleTickerProviderStateMixin {
  late AnimationController _controller;
  late Animation<Alignment> _animation;
  Alignment _dragAliment = Alignment(0, 0);

  @override
  Widget build(BuildContext context) {
    var size = MediaQuery.of(context).size;
    return GestureDetector(
      onPanStart: (details) {
        print("on pan start: $_dragAliment");
      },
      onPanDown: (details) {
        _controller.stop();
        print("on pan down: $_dragAliment");
      },
      onPanUpdate: (details) {
        _dragAliment += Alignment(details.delta.dx / (size.width / 2),
            details.delta.dy / (size.height / 2));
        runAnimation(details.delta, size);
        print("on pan update: $_dragAliment");
      },
      onPanEnd: (details) {},
      child: Align(
        child: Card(
          child: widget.child,
        ),
      ),
    );
  }

  @override
  void dispose() {
    // TODO: implement dispose
    _controller.dispose();
    super.dispose();
  }

  @override
  void initState() {
    // TODO: implement initState
    super.initState();
    _controller =
        AnimationController(vsync: this, duration: const Duration(seconds: 1));
    _animation = _controller
        .drive(AlignmentTween(begin: Alignment.center, end: _dragAliment));
    _animation.addListener(() {
      setState(() {
        _dragAliment = _animation.value;
      });
    });
  }

  void runAnimation(Offset pixelsPerSecond, Size size) {
    //数学计算
    // final unitsPerSecondX = pixelsPerSecond.dx / size.width;
    // final unitsPerSecondY = pixelsPerSecond.dy / size.height;
    // final unitsPerSecond = Offset(unitsPerSecondX, unitsPerSecondY);
    //
    // final unitVelocity = unitsPerSecond.distance;
    //
    // const spring = SpringDescription(mass: 30, stiffness: 1, damping: 1);
    //
    // final simulation = SpringSimulation(spring, 0, 1, -unitVelocity);
    // _controller.animateWith(simulation);
    _controller.reset();
    _controller.forward();
  }
}
