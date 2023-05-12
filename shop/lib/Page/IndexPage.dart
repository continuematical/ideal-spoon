import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:flutter/services.dart';
import 'package:shop/Page/HomePage.dart';
import 'package:shop/Page/LikeGoodPage.dart';
import 'package:shop/Page/MemberPage.dart';
import 'package:shop/Page/ModifyNamePage.dart';
import 'package:shop/Page/SearchPage.dart';
import 'package:shop/Page/SettingPage.dart';

import 'CartPage.dart';

class IndexPage extends StatefulWidget {
  const IndexPage({super.key});

  @override
  State<StatefulWidget> createState() => _IndexPageState();
}

//底部导航栏列表
final List<BottomNavigationBarItem> bottomNavigationItem = [
  const BottomNavigationBarItem(icon: Icon(CupertinoIcons.home), label: "小铺"),
  const BottomNavigationBarItem(icon: Icon(CupertinoIcons.search), label: "发现"),
  const BottomNavigationBarItem(
      icon: Icon(CupertinoIcons.shopping_cart), label: "购物车"),
  const BottomNavigationBarItem(
      icon: Icon(CupertinoIcons.profile_circled), label: "我的"),
];

class _IndexPageState extends State<IndexPage> {
  late DateTime lastDateTime;
  int currentIndex = 0;

  @override
  Widget build(BuildContext context) {
    return WillPopScope(
        //点击返回键的操作
        onWillPop: () async {
          if (lastDateTime == null &&
              DateTime.now().difference(lastDateTime) <
                  const Duration(seconds: 2)) {
            lastDateTime = DateTime.now();
            return false;
          } else {
            lastDateTime = DateTime.now();
            return await SystemChannels.platform
                .invokeMethod("SystemNavigator.pop");
          }
        },
        child: Scaffold(
          bottomNavigationBar: BottomNavigationBar(
              type: BottomNavigationBarType.fixed,
              currentIndex: currentIndex,
              items: bottomNavigationItem,
              onTap: (index) async {
                setState(() {
                  _controller.jumpToPage(index);
                });
              }),
          body: _getPageBody(context),
        ));
  }
}
final PageController _controller = PageController();

Widget _getPageBody(BuildContext context){
  return PageView(
    controller: _controller,
    physics: const NeverScrollableScrollPhysics(),//禁止滑动
    children: pages(),
  );
}

//页面
List<Widget> pages(){
  return [
    ModifyNamePage(name: "修改姓名"),
    const SearchPage(),
    const CartPage(),
    const MemberPage(),
  ];
}