import 'package:flutter/material.dart';
import 'package:shop/AppSize.dart';
import 'package:shop/View/CustomBar.dart';

class SettingPage extends StatefulWidget {
  const SettingPage({super.key});

  @override
  State<StatefulWidget> createState() => _SettingPageState();
}

class _SettingPageState extends State {
  @override
  Widget build(BuildContext context) {
    AppSize.init(context);
    return Scaffold(
      appBar: CustomAppBar(
          preferredSize: Size.fromHeight(AppSize.height(160)),
          child: CommonBackBar(
            title: "设置",
            onBack: () =>
            {
              Navigator.pop(context),
            },
          )),
      body: SingleChildScrollView(
        child: Column(
          children: [
            //头像
            _buildContainerHeader(),
          ],
        ),
      ),
    );
  }

  //头像
  Container _buildContainerHeader() {
    return Container(
      color: Colors.white,
      child: InkWell(
        child: Column(
          children: const [
            Padding(
              padding: EdgeInsets.only(left: 8.0),
              child: Icon(Icons.local_florist),),
            Expanded(
                flex: 1,
                child:Text("头像",
                style: TextStyle(
                  fontSize: 14,
                  decoration: TextDecoration.none
                ),),),
            Padding(
                padding: EdgeInsets.only(right: 3.0),)
          ],
        ),
      ),
    );
  }
}