import 'dart:html';

import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:flutter/services.dart';
import 'package:shop/AppSize.dart';
import 'package:shop/Resource/RegularColor.dart';
import 'package:shop/View/CustomBar.dart';
import 'package:shop/View/CustomView.dart';

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
            //修改姓名
            _buildModifyName(),
            //修改密码
            _buildModifyPwd(),
            //更换手机
            _buildChangePhone(),
            //修改性别
            _buildSex(),
            //退出
            _btnExit(),
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
              child: Icon(
                Icons.local_florist,
                size: 30,
              ),
            ),
            Expanded(
              flex: 1,
              child: Text(
                "头像",
                style: TextStyle(
                  fontSize: 14,
                  decoration: TextDecoration.none,
                ),
              ),
            ),
            Padding(
              padding: EdgeInsets.only(right: 3.0),
            )
          ],
        ),
      ),
    );
  }

  //修改姓名
  Widget _buildModifyName() {
    return InkWell(
      onTap: () {},
      child: Container(
        color: Colors.white,
        child: Column(
          children: [
            Padding(
              padding: const EdgeInsets.fromLTRB(20.0, 12.0, 20.0, 12.0),
              child: Column(
                children: [
                  Row(
                    children: const [
                      Padding(
                        padding: EdgeInsets.only(left: 8.0, right: 8.0),
                        child: Icon(
                          CupertinoIcons.profile_circled,
                          size: 30,
                        ),
                      ),
                      Expanded(
                        flex: 1,
                        child: Text(
                          "姓名",
                          style: TextStyle(
                            color: RegularColor.text_dark,
                            fontSize: 14,
                            decoration: TextDecoration.none,
                          ),
                        ),
                      ),
                      Padding(
                        padding: EdgeInsets.only(right: 3.0),
                      ),
                      Icon(Icons.keyboard_arrow_right_sharp),
                    ],
                  ),
                ],
              ),
            ),
            ThemeView.divider(),
          ],
        ),
      ),
    );
  }

  //修改密码
  Widget _buildModifyPwd() {
    return InkWell(
      onTap: () {},
      child: Container(
        color: Colors.white,
        child: Column(
          children: [
            Padding(
              padding: const EdgeInsets.fromLTRB(20.0, 12.0, 20.0, 12.0),
              child: Column(
                children: [
                  Row(
                    children: const [
                      Padding(
                          padding: EdgeInsets.only(left: 8.0, right: 8.0),
                          child: Icon(
                            Icons.lock_outline,
                            size: 30,
                          )),
                      Expanded(
                        flex: 1,
                        child: Text(
                          "修改密码",
                          style: TextStyle(
                            color: RegularColor.text_dark,
                            fontSize: 14,
                            decoration: TextDecoration.none,
                          ),
                        ),
                      ),
                      Padding(padding: EdgeInsets.only(right: 3.0)),
                      Icon(
                        Icons.keyboard_arrow_right_rounded,
                      ),
                    ],
                  ),
                ],
              ),
            ),
            ThemeView.divider(),
          ],
        ),
      ),
    );
  }

  Widget _buildChangePhone() {
    return InkWell(
      onTap: () {},
      child: Container(
        color: Colors.white,
        child: Column(
          children: [
            Padding(
              padding: const EdgeInsets.fromLTRB(20.0, 12.0, 20.0, 12.0),
              child: Column(
                children: [
                  Row(
                    children: const [
                      Padding(
                          padding: EdgeInsets.only(left: 8.0, right: 8.0),
                          child: Icon(
                            Icons.phone_forwarded,
                            size: 30,
                          )),
                      Expanded(
                        flex: 1,
                        child: Text(
                          "更换手机",
                          style: TextStyle(
                            color: RegularColor.text_dark,
                            fontSize: 14,
                            decoration: TextDecoration.none,
                          ),
                        ),
                      ),
                      Padding(padding: EdgeInsets.only(right: 3.0)),
                      Icon(
                        Icons.keyboard_arrow_right_rounded,
                      ),
                    ],
                  ),
                ],
              ),
            ),
            ThemeView.divider(),
          ],
        ),
      ),
    );
  }

  //性别
  Widget _buildSex() {
    return InkWell(
      onTap: () {},
      child: Container(
        color: Colors.white,
        child: Column(
          children: [
            Padding(
              padding: const EdgeInsets.fromLTRB(20.0, 12.0, 20.0, 12.0),
              child: Column(
                children: [
                  Row(
                    children: const [
                      Padding(
                        padding: EdgeInsets.only(left: 8.0, right: 8.0),
                        child: Icon(
                          Icons.person,
                          size: 30,
                        ),
                      ),
                      Expanded(
                        flex: 1,
                        child: Text(
                          "性别",
                          style: TextStyle(
                              color: RegularColor.text_dark,
                              fontSize: 14,
                              decoration: TextDecoration.none),
                        ),
                      ),
                      Padding(
                        padding: EdgeInsets.only(right: 3.0),
                      ),
                      Icon(Icons.keyboard_arrow_right_rounded)
                    ],
                  ),
                ],
              ),
            ),
            ThemeView.divider(),
          ],
        ),
      ),
    );
  }

  //退出
  Widget _btnExit() {
    return Container(
      margin: const EdgeInsets.only(top: 10),
      child: Center(
        child: Material(
          child: Ink(
            decoration: const BoxDecoration(
                color: Colors.blue,
                borderRadius: BorderRadius.all(Radius.circular(25.0))),
            child: InkWell(
              borderRadius: BorderRadius.circular(25.0),
              onTap: () {},
              child: Container(
                width: 300.0,
                height: 50.0,
                alignment: const Alignment(0, 0),
                child: const Text(
                  "退出登录",
                  style: TextStyle(color: Colors.white, fontSize: 16.0),
                ),
              ),
            ),
          ),
        ),
      ),
    );
  }
}
