import 'package:flutter/material.dart';
import 'package:shop/AppSize.dart';
import 'package:shop/View/CustomBar.dart';
import 'package:shop/LoadStateLayout.dart';

class SearchPage extends StatefulWidget{
  const SearchPage({super.key});

  @override
  State<StatefulWidget> createState() => _SearchPageState();
}

class _SearchPageState extends State<SearchPage>{
  final LoadState _layState = LoadState.State_Loading;
  final FocusNode _focusNode = FocusNode();
  final TextEditingController _controller = TextEditingController();

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: CustomAppBar(
        preferredSize: Size.fromHeight(AppSize.height(160)),
        child: SearchBar(
          controller: _controller,
          focusNode: _focusNode,
          valueChanged: (value) {
            var key = _controller.text;
            if(key.isEmpty){
              _getContent();
            }else{
              _doSearch(key);
            }
          },
        ),
      ),
    );
  }

  final bool _isLoading = false;
  Widget _getContent(){
    if(_isLoading){
      return const Center(
        child: CircularProgressIndicator(),
      );
    }else{
      return Container(
        padding: EdgeInsets.only(
          top: AppSize.width(30),
          left: AppSize.width(30),
          right: AppSize.width(30),
        ),
      );
    }
  }
}

//搜索
void _doSearch(String key) async{

}
