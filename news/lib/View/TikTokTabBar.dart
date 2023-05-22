import 'package:flutter/cupertino.dart';
import 'package:news/View/SelectText.dart';

enum TikTokPageTag { home, video, msg, me, follow }

class TikTokTabBar extends StatelessWidget {
  final Function(TikTokPageTag) onTabSwitch;
  final Function() onAddButton;
  final ScrollController scrollController;

  final bool hasBackground;
  final TikTokPageTag current;

  const TikTokTabBar(
      {super.key,
      required this.onTabSwitch,
      required this.onAddButton,
      required this.scrollController,
      required this.hasBackground,
      required this.current});

  @override
  Widget build(BuildContext context) {
    // TODO: implement build
    throw UnimplementedError();
  }

  Widget _getRow(){
    return Row(
      children: [
        Expanded(child: GestureDetector(
          child: SelectText,
        )),
        Expanded(child: child),
        Expanded(child: child),
        Expanded(child: child),
      ],
    );
  }
}
