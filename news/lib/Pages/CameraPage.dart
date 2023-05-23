import 'package:flutter/material.dart';
import 'package:news/Style/Style.dart';

class CameraPage extends StatefulWidget {
  @override
  State<StatefulWidget> createState() => _CameraPageState();
}

class _CameraPageState extends State<CameraPage> {
  @override
  Widget build(BuildContext context) {
    // TODO: implement build
    throw UnimplementedError();
  }

  Widget _getRightButtons() {
    return Column(
      children: const [],
    );
  }
}

class CameraButton extends StatelessWidget {
  final IconData icon;
  final String title;

  const CameraButton({super.key, required this.icon, required this.title});

  @override
  Widget build(BuildContext context) {
    return Container(
      padding: const EdgeInsets.symmetric(vertical: 8.0),
      child: DefaultTextStyle(
        style: TextStyle(shadows: [
          Shadow(
            color: Colors.black.withOpacity(0.15),
            offset: const Offset(0, 1),
            blurRadius: 1,
          )
        ]),
        child: Column(
          children: [
            Text(
              title,
              style: StandardTextStyle.small as TextStyle?,
            )
          ],
        ),
      ),
    );
  }
}
