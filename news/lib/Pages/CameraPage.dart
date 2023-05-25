import 'package:flutter/material.dart';
import 'package:news/Style/Style.dart';

class CameraPage extends StatefulWidget {
  @override
  State<StatefulWidget> createState() => _CameraPageState();
}

class _CameraPageState extends State<CameraPage> {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: SafeArea(
        child: _body,
      ),
    );
  }

  get _body {
    return Stack(
      fit: StackFit.expand,
      children: [],
    );
  }

  get rightButtons {
    return Opacity(
      opacity: 0.8,
      child: Container(
        padding: const EdgeInsets.only(right: 20, top: 12),
        alignment: Alignment.topRight,
        child: Column(
          children: const [
            CameraIconButton(icon: Icons.repeat, title: '翻转'),
            CameraIconButton(icon: Icons.tonality, title: '速度'),
            CameraIconButton(icon: Icons.texture, title: '滤镜'),
            CameraIconButton(icon: Icons.sentiment_satisfied, title: '美化'),
            CameraIconButton(icon: Icons.timer, title: '计时关'),
          ],
        ),
      ),
    );
  }

  get cameraButton {
    return Container(
      padding: const EdgeInsets.only(bottom: 12),
      alignment: Alignment.bottomCenter,
      child: Container(
        height: 80,
        padding: const EdgeInsets.symmetric(horizontal: 20),
        child: Row(
          crossAxisAlignment: CrossAxisAlignment.center,
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            const SidePhotoButton(title: '道具'),
            Expanded(
                child: Center(
              child: Container(
                height: 60,
                width: 60,
                decoration: BoxDecoration(
                    color: Colors.white.withOpacity(0.2),
                    borderRadius: BorderRadius.circular(30),
                    border: Border.all(
                      style: BorderStyle.solid,
                      color: Colors.white.withOpacity(0.4),
                      width: 6,
                    )),
              ),
            ))
          ],
        ),
      ),
    );
  }

  get closeButton {}

  get selectedMusic {
    return Container(
      padding: const EdgeInsets.only(left: 20, top: 20),
      alignment: Alignment.topCenter,
      child: DefaultTextStyle(
        style: TextStyle(shadows: [
          Shadow(
            color: Colors.black.withOpacity(0.15),
            offset: const Offset(0, 1),
            blurRadius: 1,
          )
        ]),
        child: Row(),
      ),
    );
  }
}

class CameraIconButton extends StatelessWidget {
  final IconData icon;
  final String title;

  const CameraIconButton({super.key, required this.icon, required this.title});

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

class SidePhotoButton extends StatelessWidget {
  final String title;

  const SidePhotoButton({super.key, required this.title});

  @override
  Widget build(BuildContext context) {
    return Column(
      children: [
        Container(
          height: 32,
          width: 32,
          decoration: BoxDecoration(
              color: Colors.white.withOpacity(8),
              borderRadius: BorderRadius.circular(8),
              border: Border.all(
                  style: BorderStyle.solid,
                  color: Colors.white.withOpacity(0.4),
                  width: 2)),
        ),
        Container(
          height: 2,
        ),
        Text(
          title,
          style: StandardTextStyle.normalWithOpacity as TextStyle?,
        )
      ],
    );
  }
}
