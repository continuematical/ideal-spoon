import 'package:flutter/material.dart';

enum LoadState { State_Suceess, State_Error, State_Loading, State_Empty }

class LoadStateLayout extends StatefulWidget {
  final LoadState state; //页面状态
  final Widget successWidget; //成功视图
  final VoidCallback errorRetry; //错误事件处理

  const LoadStateLayout({
    Key? key,
    this.state = LoadState.State_Loading, //默认为加载状态
    required this.successWidget,
    required this.errorRetry,
  }) : super(key: key);

  @override
  State<StatefulWidget> createState() => _LoadStateLayoutState();
}

class _LoadStateLayoutState extends State<LoadStateLayout> {
  @override
  Widget build(BuildContext context) {
    return SizedBox(
      width: double.infinity, //1.0/0.0
      height: double.infinity,
      child: _buildWidget,
    );
  }

  //根据不同状态显示不同的视图
  Widget? get _buildWidget {
    switch (widget.state) {
      case LoadState.State_Suceess:
        return widget.successWidget;
      case LoadState.State_Error:
        return _errorView;
      case LoadState.State_Loading:
        return _loadingView;
      case LoadState.State_Empty:
        return _emptyView;
      default:
        return null;
    }
  }

  //加载视图-进度显示条
  Widget get _loadingView {
    return Container(
      width: double.infinity,
      height: double.infinity,
      decoration: const BoxDecoration(color: Colors.transparent),
      alignment: Alignment.center,
      child: Container(
        height: 80,
        padding: const EdgeInsets.all(10),
        decoration: BoxDecoration(
          color: const Color(0x88000000),
          borderRadius: BorderRadius.circular(6),
        ),
        child: Column(
          mainAxisAlignment: MainAxisAlignment.spaceAround,
          children: const [CircularProgressIndicator(), Text("正在加载")],
        ),
      ),
    );
  }

  //错误视图
  Widget get _errorView {
    return SizedBox(
      width: double.infinity,
      height: double.infinity,
      child: Column(
        mainAxisAlignment: MainAxisAlignment.center,
        children: [
          Image.asset("assets/images/load_error_view.png",
          width: 100,
          height: 80,),
          const Text("加载失败，请重试"),
        ],
      ),
    );
  }

  Widget get _emptyView {
    return SizedBox(
      width: double.infinity,
      height: double.infinity,
      child: Column(
        crossAxisAlignment: CrossAxisAlignment.center,
        mainAxisAlignment: MainAxisAlignment.center,
        children: const [
          Padding(
            padding: EdgeInsets.only(top: 10),
            child: Text("暂无数据"),
          )
        ],
      ),
    );
  }
}
