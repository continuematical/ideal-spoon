import 'package:flutter/material.dart';

class SelectText extends StatelessWidget {
  final bool isSelected;
  final String title;

  const SelectText({super.key, required this.isSelected, required this.title});

  @override
  Widget build(BuildContext context) {
    return Container(
      padding: const EdgeInsets.symmetric(vertical: 12),
      color: Colors.black.withOpacity(0),
      child: Text(
        title ?? '??',
        textAlign: TextAlign.center,
      ),
    );
  }
}
