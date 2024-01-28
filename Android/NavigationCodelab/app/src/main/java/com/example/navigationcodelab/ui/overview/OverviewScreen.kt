package com.example.navigationcodelab.ui.overview

import UserData
import androidx.compose.foundation.background
import androidx.compose.foundation.clickable
import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.PaddingValues
import androidx.compose.foundation.layout.Row
import androidx.compose.foundation.layout.Spacer
import androidx.compose.foundation.layout.fillMaxWidth
import androidx.compose.foundation.layout.height
import androidx.compose.foundation.layout.padding
import androidx.compose.foundation.rememberScrollState
import androidx.compose.foundation.verticalScroll
import androidx.compose.material.icons.Icons
import androidx.compose.material.icons.filled.Send
import androidx.compose.material3.Card
import androidx.compose.material3.Icon
import androidx.compose.material3.IconButton
import androidx.compose.material3.MaterialTheme
import androidx.compose.material3.Text
import androidx.compose.material3.TextButton
import androidx.compose.runtime.Composable
import androidx.compose.runtime.getValue
import androidx.compose.runtime.mutableStateOf
import androidx.compose.runtime.remember
import androidx.compose.runtime.setValue
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.semantics.clearAndSetSemantics
import androidx.compose.ui.semantics.contentDescription
import androidx.compose.ui.semantics.semantics
import androidx.compose.ui.tooling.preview.Preview
import androidx.compose.ui.unit.dp
import com.example.navigationcodelab.ui.components.AccountRow
import com.example.navigationcodelab.ui.components.RallyAlertDialog
import java.util.Locale

private val RallyDefaultPadding = 12.dp
private const val SHOWN_ITEMS = 3

@Preview(showBackground = true)
@Composable
fun OverviewScreen(
    onClickSeeAllAccounts: () -> Unit = {},
    onClickSeeAllBills: () -> Unit = {},
    onAccountClick: (String) -> Unit = {}
) {
    Column(
        modifier = Modifier
            .padding(16.dp)
            .verticalScroll(rememberScrollState())
            .semantics { contentDescription = "Overview Screen" }
    ) {
        AlertedCard()
        Spacer(modifier = Modifier.height(RallyDefaultPadding))
        AccountCard(
            onClickSeeAll = onClickSeeAllAccounts,
            onClickAccount = onAccountClick
        )
        Spacer(modifier = Modifier.height(RallyDefaultPadding))
        BillsCard(
            onClick = onClickSeeAllBills
        )
    }
}


@Composable
private fun AlertedCard() {
    var showDialog by remember { mutableStateOf(true) }
    var alertMessage = "Heads up, you've used up 90% of your Shopping budget for this month."

    if (showDialog) {
        RallyAlertDialog(
            onDismiss = { showDialog = false },
            bodyText = alertMessage,
            buttonText = "dismiss".uppercase(Locale.getDefault())
        )
    }

    Card {
        Column {
            AlertedHeader {}
            AlertItem(
                message = "Heads up, you've used up " +
                        "90% of your Shopping budget for this month."
            )
        }
    }
}

@Composable
private fun AlertedHeader(onClick: () -> Unit) {
    Row(
        modifier = Modifier
            .padding(RallyDefaultPadding)
            .fillMaxWidth(),
        horizontalArrangement = Arrangement.SpaceBetween
    ) {
        Text(
            text = "Alerts",
            modifier = Modifier.align(Alignment.CenterVertically)
        )

        TextButton(
            onClick = onClick,
            contentPadding = PaddingValues(0.dp),
            modifier = Modifier.align(Alignment.CenterVertically)
        ) {
            Text(
                text = "See All",
            )
        }
    }
}

@Composable
private fun <T> OverviewDivider(
    data: List<T>,
    values: (T) -> Float,
    colors: (T) -> Color,
) {
    Row(Modifier.fillMaxWidth()) {
        data.forEach { it: T ->
            Spacer(
                modifier = Modifier
                    .weight(values(it))
                    .height(1.dp)
                    .background(colors(it))
            )
        }
    }
}

@Composable
private fun AlertItem(message: String) {
    Row(
        modifier = Modifier
            .padding(RallyDefaultPadding)
            .semantics(mergeDescendants = true) {}
    ) {
        Text(
            text = message,
            modifier = Modifier.weight(1f),
            style = MaterialTheme.typography.bodySmall
        )

        IconButton(
            onClick = { },
            modifier = Modifier
                .align(Alignment.Top)
                .clearAndSetSemantics {}) {
            Icon(Icons.Filled.Send, contentDescription = null)
        }
    }
}


@Composable
private fun AccountCard(onClickSeeAll: () -> Unit, onClickAccount: (String) -> Unit) {
    val amount = UserData.accounts.map { it.balance }.sum()
    OverviewScreenCard(
        title = "Accounts",
        amount = amount,
        onClick = onClickSeeAll,
        values = { it.balance },
        colors = { it.color },
        data = UserData.accounts,
    ) {
        AccountRow(
            modifier = Modifier.clickable { onClickAccount(it.name) },
            name = it.name,
            number = it.number,
            amount = it.balance,
            color = it.color
        )
    }
}


@Composable
private fun <T> OverviewScreenCard(
    title: String,
    amount: Float,
    onClick: () -> Unit,
    values: (T) -> Float,
    colors: (T) -> Color,
    data: List<T>,
    row: @Composable (T) -> Unit,
) {
    Card {
        Column {
            Column(modifier = Modifier.padding(RallyDefaultPadding)) {
                Text(text = title, style = MaterialTheme.typography.bodySmall)
            }
            OverviewDivider(data = data, values = values, colors = colors)
            Column(
                modifier = Modifier.padding(
                    start = 16.dp,
                    top = 4.dp,
                    end = 8.dp
                )
            ) {
                data.take(SHOWN_ITEMS).forEach { row(it) }
                SeeAllButton(modifier = Modifier.clearAndSetSemantics {
                    contentDescription = "All $title"
                }, onClick = onClick)
            }
        }
    }
}

@Composable
private fun BillsCard(onClick: () -> Unit) {
    val amount = UserData.bills.map { it.amount }.sum()
    OverviewScreenCard(
        title = "Bills",
        amount = amount,
        onClick = onClick,
        values = { it.amount },
        colors = { it.color },
        data = UserData.bills
    ) {

    }
}

@Composable
private fun SeeAllButton(modifier: Modifier, onClick: () -> Unit) {
    TextButton(
        onClick = onClick,
        modifier = modifier
            .height(44.dp)
            .fillMaxWidth()
    ) {
        Text("See All")
    }
}
