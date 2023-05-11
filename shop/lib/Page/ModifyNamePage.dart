import 'package:flutter/material.dart';
import 'package:shop/AppSize.dart';
import 'package:shop/Resource/RegularColor.dart';
import 'package:shop/View/CustomBar.dart';
import 'package:shop/View/CustomView.dart';

class ModifyNamePage extends StatefulWidget {
  late String name;

  ModifyNamePage({super.key, required this.name});

  @override
  State<StatefulWidget> createState() => _CreateModifyNamePageState();
}

class _CreateModifyNamePageState extends State<ModifyNamePage> {
  late String _inputText = '';

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: CustomAppBar(
          preferredSize: Size.fromHeight(AppSize.height(160)),
          child: CommonBackBar(
            title: '修改姓名',
            onBack: () => {
            Navigator.pop(context);
          },)),
      body: SingleChildScrollView(
        child: Column(
          children: [
            _buildName(),
            _btnSave(),
          ],
        ),
      ),
    );
  }

  Widget _buildName() {
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
                    const Padding(
                      padding: EdgeInsets.only(left: 8.0),
                      child: Text(
                        '*',
                      ),
                    ),
                    const Expanded(
                      flex: 1,
                      child: Text(
                        '姓名',
                        style: TextStyle(
                            color: RegularColor.text_dark,
                            fontSize: 14,
                            decoration: TextDecoration.none),
                      ),
                    ),
                    Expanded(
                        child: TextField(
                          textAlign: TextAlign.end,
                          controller: TextEditingController.fromValue(
                              TextEditingValue(
                                  text:
                                  _inputText.isEmpty ? widget.name : _inputText,
                                  selection: TextSelection.fromPosition(
                                      TextPosition(
                                          offset: _inputText.isEmpty
                                              ? widget.name.length
                                              : _inputText.length,
                                          affinity: TextAffinity.downstream)))),
                          decoration: const InputDecoration(
                            border: InputBorder.none,
                            hintText: "请输入姓名",
                            hintStyle:
                            TextStyle(color: Colors.grey, fontSize: 15.0),
                          ),
                          onChanged: (inputStr) {
                            _inputText = inputStr;
                          },
                        ))
                  ],
                ),
              ],
            ),
          ),
          ThemeView.divider(),
        ],
      ),
    );
  }

  Widget _btnSave() {
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
                if (_inputText.isEmpty) {
                  //对话框
                } else {
                  loadSave();
                }
              },
              child: Container(
                width: 300.0,
                height: 50.0,
                alignment: const Alignment(0, 0),
                child: const Text(
                  "保 存",
                  style: TextStyle(
                    fontSize: 16.0,
                    color: Colors.white,
                  ),
                ),
              ),
            ),
          ),
        ),
      ),
    );
  }

  void loadSave() {}
}
