package com.example.navigationcodelab.ui.bills

import Bill
import UserData
import androidx.compose.runtime.Composable
import androidx.compose.runtime.remember
import androidx.compose.ui.res.stringResource
import com.example.navigationcodelab.R
import com.example.navigationcodelab.ui.components.BillRow
import com.example.navigationcodelab.ui.components.StatementBody

/**
 * The Bill Screen
 */

@Composable
fun BillScreen(
    bills: List<Bill> = remember {
        UserData.bills
    }
) {
    StatementBody(
        items = bills,
        colors = { bill -> bill.color },
        amounts = { bill -> bill.amount },
        amountsTotal = bills.map { bill -> bill.amount }.sum(),
        circleLabel = stringResource(id = R.string.due),
        rows = { bill
            ->
            BillRow(
                color = bill.color,
                name = bill.name,
                due = bill.due,
                amount = bill.amount
            )
        }
    )
}