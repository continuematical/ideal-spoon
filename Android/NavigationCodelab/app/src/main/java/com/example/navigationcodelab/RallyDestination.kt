package com.example.navigationcodelab

import androidx.compose.material.icons.Icons
import androidx.compose.material.icons.filled.Add
import androidx.compose.material.icons.filled.Build
import androidx.compose.material.icons.filled.Face
import androidx.compose.material.icons.filled.Person
import androidx.compose.runtime.Composable
import androidx.compose.ui.graphics.vector.ImageVector
import com.example.navigationcodelab.ui.accounts.AccountScreen
import com.example.navigationcodelab.ui.accounts.SingleAccountScreen
import com.example.navigationcodelab.ui.bills.BillScreen
import com.example.navigationcodelab.ui.overview.OverviewScreen

interface RallyDestination {
    val icon: ImageVector
    val route: String
    val screen: @Composable () -> Unit
}

//object用来声明类，在声明类的同时创建一个实例
object Account : RallyDestination {
    override val icon: ImageVector = Icons.Filled.Add
    override val route = "account"
    override val screen: @Composable () -> Unit = { AccountScreen() }
}

object Overview : RallyDestination {
    override val icon: ImageVector = Icons.Filled.Person
    override val route = "overview"
    override val screen: @Composable () -> Unit = { OverviewScreen() }
}

object Bills : RallyDestination {
    override val icon: ImageVector = Icons.Filled.Build
    override val route: String = "bills"
    override val screen: @Composable () -> Unit = { BillScreen() }
}

object SingleAccount : RallyDestination {
    override val icon: ImageVector = Icons.Filled.Face
    override val route: String = "single_account"
    override val screen: @Composable () -> Unit = { SingleAccountScreen() }
    const val accountTypeArg = "account_type"
}

val rallyTabRowScreens = listOf(Overview, Account, Bills)