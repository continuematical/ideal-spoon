import 'package:flutter/material.dart';
import 'package:news/Style/Style.dart';
import 'package:news/View/SelectText.dart';

enum TikTokPageTag { home, video, msg, me, follow }

class TikTokTabBar extends StatelessWidget {
  final Function(TikTokPageTag) onTabSwitch;
  final Function() onAddButton;
  final ScrollController scrollController;

  final bool hasBackground;

  ///是否有背景
  final TikTokPageTag current;

  ///当前选中的标签

  const TikTokTabBar(
      {super.key,
      required this.onTabSwitch,
      required this.onAddButton,
      required this.scrollController,
      required this.hasBackground,
      required this.current});

  @override
  Widget build(BuildContext context) {
    /// MediaQuery 获取屏幕信息
    /// 处理设备和组件问题等
    final EdgeInsets padding = MediaQuery.of(context).padding;

    return Container(
      /// 调整颜色透明度
      color: hasBackground ? ColorPlate.back2 : ColorPlate.back2.withOpacity(0),
      child: Container(
        padding: EdgeInsets.only(bottom: padding.bottom),
        height: 50 + padding.bottom,
        child: _getRow(),
      ),
    );
  }

  Widget _getRow() {
    return Row(
      children: [
        Expanded(

            ///手势检测
            child: GestureDetector(
          onTap: () {
            onTabSwitch?.call(TikTokPageTag.home);
            if (current == TikTokPageTag.home) {}
          },
          child: SelectText(
            isSelected: current == TikTokPageTag.home,
            title: '首页',
          ),
        )),
        Expanded(
            child: GestureDetector(
          onTap: () {
            onTabSwitch?.call(TikTokPageTag.video);
          },
          child: SelectText(
            isSelected: current == TikTokPageTag.video,
            title: '视频',
          ),
        )),
        Expanded(
            child: GestureDetector(
          onTap: () => onAddButton?.call(),
          child: const Icon(
            Icons.add_box,
            size: 32,
          ),
        )),
        Expanded(
            child: GestureDetector(
          child: SelectText(
            isSelected: current == TikTokPageTag.msg,
            title: '消息',
          ),
        )),
        Expanded(
            child: GestureDetector(
          onTap: () {
            onTabSwitch?.call(TikTokPageTag.me);
          },
          child: SelectText(
            isSelected: current == TikTokPageTag.me,
            title: '我的',
          ),
        )),
      ],
    );
  }
}
