import 'package:dio/dio.dart';
import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:shop/AppSize.dart';
import 'package:shop/View/CustomBar.dart';
import 'package:shop/LoadStateLayout.dart';

import '../../Model/Good.dart';

class CartPage extends StatefulWidget {
  const CartPage({super.key});

  @override
  State<StatefulWidget> createState() => _CartPageState();
}

class _CartPageState extends State<CartPage> {
  final LoadState _layoutState = LoadState.State_Suceess;
  List<GoodsModel> goodList = [];
  final bool _isLoading = false;
  final bool _isAllCheck = true;

  @override
  void initState() {
    // TODO: implement initState
    super.initState();
  }

  @override
  Widget build(BuildContext context) {
    AppSize.init(context);
    return Scaffold(
      appBar: CustomAppBar(
        preferredSize: Size.fromHeight(AppSize.height(160)),
        child: const CommonTopBar(title: "购物车"),
      ),
      body: LoadStateLayout(
        successWidget: _getContent(),
        errorRetry: () {},
        state: _layoutState,
      ),
    );
  }

  Widget _getContent() {
    if (_isLoading) {
      return const Center(
        child: CircularProgressIndicator(),
      );
    } else {
      return SizedBox(
        width: double.infinity,
        height: double.infinity,
        child: Column(
          children: [
            const SizedBox(
              width: double.infinity,
              height: 128,
            ),
            const Icon(
              CupertinoIcons.shopping_cart,
              size: 128,
            ),
            const Text("还未登录",
                textAlign: TextAlign.center,
                style: TextStyle(
                  fontSize: 20,
                )),
            Container(
              margin: const EdgeInsets.only(top: 30),
              child: Center(
                child: Material(
                  child: Ink(
                      decoration: const BoxDecoration(
                        color: Colors.blue,
                        borderRadius: BorderRadius.all(Radius.circular(25.0)),
                      ),
                      child: InkWell(
                        borderRadius:
                            const BorderRadius.all(Radius.circular(25.0)),
                        onTap: () {},
                      )),
                ),
              ),
            ),
          ],
        ),
      );
    }
  }
}
