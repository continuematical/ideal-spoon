import 'package:flutter/material.dart';
import 'package:shop/Resource/RegularColor.dart';
import 'package:shop/View/CustomView.dart';

class ModifyPwdPage extends StatefulWidget {
  const ModifyPwdPage({super.key});

  @override
  State<StatefulWidget> createState() => _CreateModifyPwdPage();
}

class _CreateModifyPwdPage extends State<ModifyPwdPage> {
  String _inputOldStr = ' '; //旧密码
  String _inputNewStr = ' '; //新密码
  String _inputAgainStr = ' '; //再一次输入密码

  @override
  Widget build(BuildContext context) {
    return Container(
      color: Colors.white,
      child: Center(
        child: Column(
          children: [
            _buildPwdNew(),
            _buildPwdOld(),
            _buildPwdAgain(),
          ],
        ),
      )
    );
  }

  Widget _buildPwdOld() {
    return Container(
      color: Colors.white,
      child: Column(
        children: [
          Padding(
              padding: const EdgeInsets.fromLTRB(20.0, 6.0, 20.0, 6.0),
              child: Row(
                children: [
                  Padding(
                      padding: const EdgeInsets.only(left: 8.0),
                      child: Text(
                        "*",
                        style: ThemeTextStyle.cardPriceStyle,
                      )),
                  const Expanded(
                    flex: 1,
                    child: Text(
                      '旧密码',
                      style: TextStyle(
                        color: RegularColor.text_dark,
                        fontSize: 14,
                        decoration: TextDecoration.none,
                      ),
                    ),
                  ),
                  Expanded(
                      child: TextField(
                          textAlign: TextAlign.end,
                          keyboardType: TextInputType.text,
                          obscureText: true,
                          decoration: const InputDecoration(
                            border: InputBorder.none,
                            hintText: '请输入密码',
                            hintStyle: TextStyle(
                              color: Colors.grey,
                              fontSize: 15.0,
                            ),
                          ),
                          onChanged: (inputStr) {
                            _inputOldStr = inputStr;
                          }))
                ],
              )),
          ThemeView.divider(),
        ],
      ),
    );
  }

  Widget _buildPwdNew() {
    return Container(
      color: Colors.white,
      child: Column(
        children: [
          Padding(
            padding: const EdgeInsets.fromLTRB(20.0, 6.0, 20.0, 6.0),
            child: Column(
              children: [
                Row(
                  children: [
                    Padding(
                      padding: const EdgeInsets.only(left: 8.0),
                      child: Text(
                        '*',
                        style: ThemeTextStyle.cardPriceStyle,
                      ),
                    ),
                    const Expanded(
                      flex: 1,
                      child: Text(
                        '新密码',
                        style: TextStyle(
                          color: RegularColor.text_dark,
                          fontSize: 14.0,
                          decoration: TextDecoration.none,
                        ),
                      ),
                    ),
                    Expanded(
                        child: TextField(
                      textAlign: TextAlign.end,
                      obscureText: true,
                      keyboardType: TextInputType.text,
                      decoration: const InputDecoration(
                          hintText: '请输入新密码',
                          hintStyle: TextStyle(
                            color: Colors.grey,
                            fontSize: 15.0,
                          )),
                      onChanged: (inputStr) {
                        _inputNewStr = inputStr;
                      },
                    )),
                  ],
                ),
                ThemeView.divider(),
              ],
            ),
          )
        ],
      ),
    );
  }

  Widget _buildPwdAgain() {
    return Container(
      color: Colors.white,
      child: Column(
        children: [
          Padding(
            padding: const EdgeInsets.fromLTRB(20.0, 6.0, 20.0, 6.0),
            child: Column(
              children: [
                Row(
                  children: [
                    Padding(
                      padding: const EdgeInsets.only(left: 8.0),
                      child: Text(
                        '*',
                        style: ThemeTextStyle.cardPriceStyle,
                      ),
                    ),
                    const Expanded(
                      flex: 1,
                      child: Text(
                        '确认密码',
                        style: TextStyle(
                          color: RegularColor.text_dark,
                          fontSize: 14.0,
                          decoration: TextDecoration.none,
                        ),
                      ),
                    ),
                    Expanded(
                        child: TextField(
                      textAlign: TextAlign.end,
                      obscureText: true,
                      keyboardType: TextInputType.text,
                      decoration: const InputDecoration(
                          hintText: '请确认密码',
                          hintStyle: TextStyle(
                            color: Colors.grey,
                            fontSize: 15.0,
                          )),
                      onChanged: (inputStr) {
                        _inputAgainStr = inputStr;
                      },
                    )),
                  ],
                ),
                ThemeView.divider(),
              ],
            ),
          )
        ],
      ),
    );
  }

  Widget _buildSave() {
    return Container(
        margin: const EdgeInsets.only(top: 10),
        child: Center(
          child: Material(
            child: Ink(
              decoration: const BoxDecoration(
                color: Colors.blue,
                borderRadius: BorderRadius.all(Radius.circular(25.0)),
              ),
              child: InkWell(
                borderRadius: BorderRadius.circular(25.0),
                onTap: () {
                  if (_inputOldStr.isEmpty) {}
                  if (_inputNewStr.isEmpty) {}
                  if (_inputAgainStr.isEmpty) {}
                },
                child: Container(
                  width: 30.0,
                  height: 30.0,
                  alignment: Alignment.center,
                  child: const Text(
                    '保 存',
                    style: TextStyle(color: Colors.white, fontSize: 16.0),
                  ),
                ),
              ),
            ),
          ),
        ));
  }
}
