import 'package:flutter/material.dart';
import 'package:shop/AppSize.dart';
import 'package:shop/View/CustomBar.dart';
import 'package:shop/LoadStateLayout.dart';

import '../Model/Category.dart';
import '../Model/Good.dart';

class HomePage extends StatefulWidget {
  const HomePage({super.key});

  @override
  State<StatefulWidget> createState() => _HomePageState();
}

class _HomePageState extends State<HomePage> {
  //页面状态
  LoadState _layoutState = LoadState.State_Empty;
  double width = 0;

  //标签
  List<Tab> myTabs = <Tab>[];

  @override
  Widget build(BuildContext context) {
    AppSize.init(context);
    if (myTabs.isNotEmpty) {

    }
    return Scaffold(
      appBar: CustomAppBar(
        preferredSize: Size.fromHeight(AppSize.height(160)),
        child: const CommonTopBar(
          title: "小铺",
        ),
      ),
      body: LoadStateLayout(
        state: _layoutState,
        errorRetry: () {
          setState(() {
            _layoutState = LoadState.State_Loading;
          });
        },
        successWidget: Container(
          color: Colors.blue,
          child: Column(
            children: [
              Container(
                color: Colors.white,
                height: AppSize.height(120),
                child: Row(
                  children: [
                    Expanded(
                        child: TabBar(
                            tabs: myTabs,
                            isScrollable: true,
                            //可以滑动
                            indicatorSize: TabBarIndicatorSize.tab,
                            indicatorWeight: 1.0,
                            unselectedLabelColor: const Color(0xff333333),
                            labelStyle: TextStyle(fontSize: AppSize.sp(44)),
                            indicatorPadding: EdgeInsets.only(
                                left: AppSize.width(width),
                                right: AppSize.width(width)),
                            labelPadding: EdgeInsets.only(
                                left: AppSize.width(width),
                                right: AppSize.width(width)))),
                    const Expanded(
                        child: TabBarView(
                          children: [],
                        ))
                  ],
                ),
              )
            ],
          ),
        ),
      ),
    );
  }

  //加载大类列表和标签
  loadCategoryData() async{
    _layoutState = LoadState.State_Error;
  }
}

//子页面
class FindingTabView extends StatefulWidget {
  final int currentPage;
  final String id;
  final List<CategoryInfoModel> categoryInfoModels;

  const FindingTabView(
      {super.key, required this.currentPage, required this.id, required this.categoryInfoModels,});

  @override
  State<StatefulWidget> createState() => _FindingTabView();
}

class _FindingTabView extends State<FindingTabView> {
  final GlobalKey _headerKey = GlobalKey();
  final GlobalKey _footerKey = GlobalKey();
  final LoadState _layoutState = LoadState.State_Loading;

  //新品推荐
  List<GoodsModel> goodsList = <GoodsModel>[];
  //热门推荐
  List<GoodsModel> hotGoodsList = <GoodsModel>[];
  //是否正在加载
  bool _isLoading = false;

  @override
  void initState() {
    _isLoading = true;
    // TODO: implement initState
    super.initState();
  }
  @override
  Widget build(BuildContext context) {
    // TODO: implement build
    throw UnimplementedError();
  }
}
