package com.example.navigationcodelab.ui.accounts

import UserData
import androidx.compose.foundation.clickable
import androidx.compose.runtime.Composable
import androidx.compose.runtime.remember
import androidx.compose.ui.Modifier
import androidx.compose.ui.res.stringResource
import androidx.compose.ui.semantics.contentDescription
import androidx.compose.ui.semantics.semantics
import com.example.navigationcodelab.R
import com.example.navigationcodelab.ui.components.AccountRow
import com.example.navigationcodelab.ui.components.StatementBody

/**
 * The Accounts Screen
 */

@Composable
fun AccountScreen(
    onAccountClick: (String) -> Unit = {}
) {
    val amountsTotal = remember {
        UserData.accounts.map { account -> account.balance }.sum()
    }
    StatementBody(
        modifier = Modifier.semantics {
            contentDescription = "Accounts Screen"
        },
        items = UserData.accounts,
        colors = { account -> account.color },
        amounts = { account -> account.balance },
        amountsTotal = amountsTotal,
        circleLabel = stringResource(id = R.string.total),
        rows = { account ->
            AccountRow(
                modifier = Modifier.clickable {
                    onAccountClick(account.name)
                },
                name = account.name,
                number = account.number,
                amount = account.balance,
                color = account.color
            )
        }
    )
}


/**
 * Detailed screen for a single account
 */
@Composable
fun SingleAccountScreen(
    accountType: String? = UserData.accounts.first().name
) {
    val account = remember(accountType) {
        UserData.getAccount(accountType)
    }
    StatementBody(
        items = listOf(account),
        colors = { account -> account.color },
        amounts = { account -> account.balance },
        amountsTotal = account.balance,
        circleLabel = account.name,
        rows = { account ->
            AccountRow(
                name = account.name,
                number = account.number,
                amount = account.balance,
                color = account.color
            )
        }
    )
}