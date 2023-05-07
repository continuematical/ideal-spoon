import 'package:flutter/material.dart';
import 'package:shop/AppSize.dart';
import 'package:shop/View/CustomBar.dart';

class LikeGoodPage extends StatefulWidget {
  const LikeGoodPage({super.key});

  @override
  State<StatefulWidget> createState() => _LikeGoodPageState();
}

class _LikeGoodPageState extends State<LikeGoodPage> {
  @override
  Widget build(BuildContext context) {
    AppSize.init(context);
    return Scaffold(
      appBar: CustomAppBar(
        preferredSize: Size.fromHeight(AppSize.height(160)),
        child: CommonRightBar(
          title: "喜欢的商品",
          menu: "编辑",
          onBack: () {
            Future.delayed(const Duration(milliseconds: 500), () {
              Navigator.pop(context);
            });
          },
          onMenu: () {},
        ),
      ),
      body: const Center(
        child: Text(
          '商品列表',
          textDirection: TextDirection.ltr,
          style: TextStyle(
            fontSize: 40.0,
            color: Colors.yellow,
            fontWeight: FontWeight.bold,
          ),
        ),
      ),
    );
  }
}
