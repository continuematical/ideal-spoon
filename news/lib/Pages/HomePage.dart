import 'package:flutter/material.dart';
import 'package:news/Util/StringResource.dart';

class App extends StatelessWidget{
  const App({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: StringResource.APP_NAME,
      color: Colors.white,
      home: HomePage(title: StringResource.APP_NAME,),
    );
  }
}

class HomePage extends StatefulWidget{
  late String title;

  HomePage({super.key, required this.title});

  @override
  State<StatefulWidget> createState() => _CreateHomePage();
}

class _CreateHomePage extends State<HomePage>{

  @override
  Widget build(BuildContext context) {
    // TODO: implement build
    throw UnimplementedError();
  }
}