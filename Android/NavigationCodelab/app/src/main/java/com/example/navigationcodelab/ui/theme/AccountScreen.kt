package com.example.navigationcodelab.ui.theme

import UserData
import androidx.compose.runtime.Composable
import androidx.compose.runtime.remember

@Composable
fun AccountScreen(
    onAccountClick: (String) -> Unit = {}
) {
    val amountsTotal = remember {
        UserData.accounts.map { account -> account.balance }.sum()
    }

}