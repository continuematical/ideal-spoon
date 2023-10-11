import 'package:flutter/material.dart';
import 'package:flutter/services.dart';
import 'package:shop/AppSize.dart';
import 'package:shop/View/IconFonts.dart';

class CustomAppBar extends StatelessWidget implements PreferredSizeWidget {
  @override
  final Size preferredSize;
  final Widget child;

  const CustomAppBar(
      {super.key, required this.preferredSize, required this.child});

  @override
  Widget build(BuildContext context) {
    return Container(
      padding: const EdgeInsets.only(left: 6, right: 6),
      decoration: const BoxDecoration(
          gradient: LinearGradient(
        colors: [Color(0xff00c2fd), Color(0xff00c2fd)],
        begin: Alignment.topCenter,
        end: Alignment.bottomCenter,
      )),
      height: preferredSize.height,
      child: child,
    );
  }
}

//搜索框
class SearchBar extends StatelessWidget {
  final TextEditingController controller;
  final FocusNode focusNode;
  final ValueChanged valueChanged;

  const SearchBar({
    super.key,
    required this.controller,
    required this.focusNode,
    required this.valueChanged,
  });

  @override
  Widget build(BuildContext context) {
    return Stack(
      children: [
        Center(
          child: Container(
            width: AppSize.width(750),
            height: AppSize.height(72),
            decoration: BoxDecoration(
              color: Colors.white,
              borderRadius: BorderRadius.circular(20.0),
            ),
            child: TextField(
              keyboardType: TextInputType.text,
              textInputAction: TextInputAction.done,
              maxLines: 1,
              inputFormatters: [
                LengthLimitingTextInputFormatter(10),
              ],
              onChanged: (str) {
                valueChanged;
              },
              focusNode: focusNode,
              controller: controller,
              decoration: InputDecoration(
                  hintText: "请输入商品名称",
                  hintStyle: TextStyle(
                      fontSize: AppSize.sp(35), color: const Color(0xff999999)),
                  border: InputBorder.none,
                  prefixIcon: const Icon(Icons.search),
                  contentPadding:
                      EdgeInsets.symmetric(vertical: AppSize.height(25))),
            ),
          ),
        ),
      ],
    );
  }
}

//返回
class CommonBackBar extends StatelessWidget {
  final String title;
  final Function() onBack;

  const CommonBackBar({
    super.key,
    required this.title,
    required this.onBack,
  });

  @override
  Widget build(BuildContext context) {
    return Stack(
      children: [
        Center(
          child: Text(
            title,
            softWrap: true,
            textAlign: TextAlign.center,
            overflow: TextOverflow.ellipsis,
            maxLines: 1,
            style: TextStyle(
              color: Colors.white,
              fontSize: AppSize.sp(52),
            ),
          ),
        ),
        InkWell(
          onTap: onBack,
          child: Column(
            mainAxisAlignment: MainAxisAlignment.center,
            mainAxisSize: MainAxisSize.max,
            children: [
              Padding(
                padding: EdgeInsets.only(left: AppSize.width(20)),
                child: Icon(
                  Icons.keyboard_arrow_left,
                  color: Colors.white,
                  size: AppSize.height(90),
                ),
              )
            ],
          ),
        ),
      ],
    );
  }
}

//顶部标题
class CommonTopBar extends StatelessWidget {
  final String title;

  const CommonTopBar({super.key, required this.title});

  @override
  Widget build(BuildContext context) {
    return Center(
      child: Text(
        title,
        style: TextStyle(
          color: Colors.white,
          fontSize: AppSize.sp(32),
        ),
      ),
    );
  }
}

class CommonRightBar extends StatelessWidget {
  late String title;
  late String menu;
  late Function onBack;
  late Function onMenu;

  CommonRightBar({
    super.key,
    required this.title,
    required this.menu,
    required this.onBack,
    required this.onMenu,
  });

  @override
  Widget build(BuildContext context) {
    return Row(
      children: [
        InkWell(
          onTap: onBack(),
          child: Container(
            width: AppSize.width(120),
            padding: EdgeInsets.only(left: AppSize.width(10)),
            child: Icon(
              Icons.keyboard_arrow_left_rounded,
              color: Colors.white,
              size: AppSize.width(30),
            ),
          ),
        ),
        Container(
          width: AppSize.width(750),
          padding: EdgeInsets.only(left: AppSize.width(100)),
          child: Text(
            title,
            softWrap: true,
            textAlign: TextAlign.center,
            maxLines: 1,
            style: TextStyle(
              color: Colors.white,
              fontSize: AppSize.sp(52),
            ),
          ),
        ),
        InkWell(
          onTap: onMenu(),
          child: Container(
            width: AppSize.width(120),
            padding: EdgeInsets.only(right: AppSize.width(10)),
            child: Text(
              menu,
              softWrap: true,
              maxLines: 1,
              textAlign: TextAlign.center,
              overflow: TextOverflow.ellipsis,
              style: TextStyle(color: Colors.white, fontSize: AppSize.sp(52)),
            ),
          ),
        ),
      ],
    );
  }
}
