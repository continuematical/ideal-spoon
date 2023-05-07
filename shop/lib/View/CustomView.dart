import 'package:flutter/material.dart';

class ThemeView {
  static Widget divider({Orientation orientation = Orientation.landscape}) {
    if (orientation == Orientation.landscape) {
      return const Divider(height: 0.0, color: Color(0xffdedede));
    } else {
      return const VerticalDivider(
        width: 0.0,
        color: Color(0xffdedede),
      );
    }
  }
}
