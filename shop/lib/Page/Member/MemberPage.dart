import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:shop/AppSize.dart';
import 'package:shop/View/CustomBar.dart';

class MemberPage extends StatelessWidget {
  const MemberPage({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: CustomAppBar(
          preferredSize: Size.fromHeight(AppSize.height(160)),
          child: const CommonTopBar(
            title: "我的",
          )),
      body: ListView(
        children: [
          _topHeader(),
          _orderType(context),
          _orderTitle(context),
          _actionList(context),
        ],
      ),
    );
  }

  //头像
  Widget _topHeader() {
    return SizedBox(
      width: double.infinity,
      height: AppSize.height(450),
      child: Icon(
        Icons.add_business_outlined,
        size: AppSize.width(128),
      ),
    );
  }

  //我的订单顶部
  Widget _orderTitle(BuildContext context) {
    return InkWell(
      onTap: () {},
      child: Container(
        decoration: const BoxDecoration(
          color: Colors.white,
          border: Border(bottom: BorderSide(width: 1, color: Colors.black12)),
        ),
        child: const ListTile(
          leading: Icon(Icons.assessment),
          title: Text("全部订单"),
          trailing: Icon(Icons.arrow_right),
        ),
      ),
    );
  }

  //收货类型
  Widget _orderType(BuildContext context) {
    return Container(
      margin: const EdgeInsets.only(top: 5),
      width: AppSize.width(1080),
      height: AppSize.height(160),
      color: Colors.white,
      child: Row(
        children: [
          InkWell(
            child: SizedBox(
              width: AppSize.width(270),
              child: Column(
                children: const [
                  Icon(
                    Icons.business,
                    size: 30,
                  ),
                  Text("待付款"),
                ],
              ),
            ),
          ),
          InkWell(
            child: SizedBox(
              width: AppSize.width(270),
              child: Column(
                children: const [
                  Icon(
                    Icons.directions_train_sharp,
                    size: 30,
                  ),
                  Text("待发货"),
                ],
              ),
            ),
          ),
          InkWell(
            child: SizedBox(
              width: AppSize.width(270),
              child: Column(
                children: const [
                  Icon(
                    Icons.add_alert_rounded,
                    size: 30,
                  ),
                  Text("已发货"),
                ],
              ),
            ),
          ),
          InkWell(
            child: SizedBox(
              width: AppSize.width(270),
              child: Column(
                children: const [
                  Icon(
                    Icons.school,
                    size: 30,
                  ),
                  Text("已完成"),
                ],
              ),
            ),
          ),
        ],
      ),
    );
  }

  Widget _getList(String title, Icon icon) {
    return InkWell(
      child: Container(
        decoration: const BoxDecoration(
            color: Colors.white,
            border: Border(
              bottom: BorderSide(width: 1, color: Colors.black12),
            )),
        child: ListTile(
          leading: icon,
          title: Text(title),
          trailing: const Icon(Icons.arrow_right),
        ),
      ),
    );
  }

  Widget _actionList(BuildContext context){
    return Container(
      margin: const EdgeInsets.only(top: 30),
      child: Column(
        children: [
          _getList("我的收藏",const Icon(Icons.star_border)),
          _getList("设置", const Icon(CupertinoIcons.gear_big))
        ],
      ),
    );
  }
}
