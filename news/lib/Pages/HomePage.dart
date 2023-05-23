import 'package:flutter/material.dart';
import 'package:news/Pages/CameraPage.dart';
import 'package:news/Style/Theme.dart';
import 'package:news/Util/StringResource.dart';
import 'package:news/View/TikTokTabBar.dart';

class App extends StatelessWidget {
  const App({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: StringResource.APP_NAME,
      color: Colors.white,
      home: HomePage(
        title: StringResource.APP_NAME,
      ),
    );
  }
}

class HomePage extends StatefulWidget {
  late String title;

  HomePage({super.key, required this.title});

  @override
  State<StatefulWidget> createState() => _CreateHomePage();
}

class _CreateHomePage extends State<HomePage> {
  TikTokPageTag tag = TikTokPageTag.home;
  ScrollController controller = ScrollController();

  @override
  Widget build(BuildContext context) {
    // TODO: implement build
    throw UnimplementedError();
  }

  Widget _getTabBar() {
    int currentPage = 0;
    switch (tag) {
      default:
        currentPage = tag.index;
    }

    /// 获取屏幕比值
    /// 是否具有底页面
    bool hasBottomPadding = MediaQuery.of(context).size.aspectRatio < 0.55;
    bool hasBackground = tag != TikTokPageTag.home;

    if (hasBottomPadding) {
      hasBackground = true;
    }

    /// Theme是一个将主题应用于子组件的组件
    return Theme(
      /// 设置主题
      data: ThemeColor.themeColor,
      child: TikTokTabBar(
        hasBackground: hasBackground,
        current: tag,
        scrollController: controller,
        onAddButton: () {
          Navigator.of(context).push(MaterialPageRoute(builder: (context) {
            return Theme(data: ThemeColor.themeColor, child: CameraPage());
          }));
        },
        onTabSwitch: (type) async {
          setState(() {
            tag = type;
            if (type == TikTokPageTag.video) {
            } else {}
          });
        },
      ),
    );
  }
}
