import 'package:flutter/material.dart';
import 'package:shop/Resource/RegularColor.dart';
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
}
