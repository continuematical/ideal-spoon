// @ts-nocheck
import securityLabel from '@ohos.file.securityLabel'
import CommonConstants from '../contants/CommonConstants'
import Logger from './Logger'

export class CommonUtils {
  alertDialog() {
    AlertDialog.show({
      message: $r('app.string.alert_dialog_message'),
      alignment: DialogAlignment.Bottom,
      offset: { //相对于alignment的偏移量
        dx: 0,
        dy: CommonConstants.DY_OFFSET
      },
      primaryButton: {
        value: $r('app.string.cancel_button'),
        action: () => {
          Logger.info(CommonConstants.TAG_COMMON_UTILS, 'Callback button is clicked')
        }
      },
      secondaryButton: {
        value: $r('app.string.definite_button'),
        action: () => {
          Logger.info(CommonConstants.TAG_COMMON_UTILS, 'Callback definite button is clicked')
        }
      }
    })
  }

  datePickerDialog(dateCallback) {
    DatePickerDialog.show({
      start: new Date(CommonConstants.START_TIME),
      end: new Date(),
      selected: new Date(CommonConstants.SELECT_TIME),
      lunar: false,
      onAccept: (value: DatePickerResult) => {
        let year = value.year
        let month = value.month
        let day = value.day
        let birthdate: string = this.getBirthDateValue(year, month, day)
        dateCallback(birthdate)
      }
    })
  }

  textPickerDialog(sexArray: Resource, sexCallback) {
    if (this.isEmptyArr(sexArray)) {
      Logger.error(CommonConstants.TAG_COMMON_UTILS, 'sex is null')
      return
    }
    TextPickerDialog.show({
      range: sexArray,
      selected: 0,
      onAccept: ((value: TextPickerResult) => {
        sexCallback(value.value)
      }),
      onCancel: (() => {
        Logger.info(CommonConstants.TAG_COMMON_UTILS, 'TextPickerDialog onCancel')
      })
    })
  }

  getBirthDateValue(year: number, month: number, day: number): string {
    let birthDate: string = `${year}${CommonConstants.DATE_YEAR}${month}` +
    `${CommonConstants.DATE_MONTH}${day}${CommonConstants.DATE_DAY}`
    return birthDate
  }

  isEmptyArr(array): boolean {
    return this.isEmptyArr(array) || array.length === 0
  }

  idEmpty(obj): boolean {
    return obj === undefined || obj === null || obj === '';
  }
}

export default new CommonUtils()