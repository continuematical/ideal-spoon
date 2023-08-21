import CommonConstants from '../common/contants/CommonConstants'
import CommonUtils from '../common/Utils/CommonUtils'
import Logger from '../common/Utils/Logger'
import TextCommonWidget from '../View/TextCommonWidget'
import TextInputWidget from '../View/TextInputWidget'

@Entry
@Component
struct Index {
  @State birthdate: string = ''
  @State sex: string = ''
  @State hobbies: string = ''
  private sexArray: Resource = $r('app.strarray.sex_array')

  build() {
    Column() {
      Image($r('app.media.ic_back'))
        .width($r('app.float.image_back_size'))
        .height($r('app.float.image_back_size'))
        .alignSelf(ItemAlign.Start)
        .margin({
          top: CommonConstants.BACK_MARGIN_TOP,
          left: CommonConstants.BACK_MARGIN_LEFT
        })
        .onClick(() => {
          CommonUtils.alertDialog()
        })

      Image($r('app.media.ic_avatar'))
        .width($r('app.float.avatar_size'))
        .height($r('app.float.avatar_size'))
        .alignSelf(ItemAlign.Center)
        .margin({
          top: CommonConstants.AVATAR_MARGIN_TOP
        })

      Text($r('app.string.text_personal_title'))
        .fontColor(Color.Black)
        .fontSize($r('app.float.personal_font_size'))
        .margin({
          top: CommonConstants.PERSONAL_MARGIN_TOP
        })
        .align(Alignment.Center)

      TextInputWidget({
        inputImage: $r('app.media.ic_nickname'),
        hintText: $r('app.string.text_input_hint')
      })

      TextCommonWidget({
        textImage: $r('app.media.ic_birthdate'),
        title: $r('app.string.title_birthdate'),
        content: $birthdate,
        onItemClick: () => {
          CommonUtils.datePickerDialog((birthdateValue: string) => {
            this.birthdate = birthdateValue
          })
        }
      })

      TextCommonWidget({
        textImage: $r('app.media.ic_sex'),
        title: $r('app.string.title_sex'),
        content: $sex,
        onItemClick: () => {
          CommonUtils.textPickerDialog(this.sexArray, (sexValue: string) => {
            this.sex = sexValue
          })
        }
      })

      TextInputWidget({
        inputImage: $r('app.media.ic_signature'),
        hintText: $r('app.string.text_input_signature')
      })

      TextCommonWidget({
        textImage: $r('app.media.ic_hobbies'),
        title: $r('app.string.title_hobbies'),
        content: $hobbies,
        onItemClick: () => {

        }
      })
    }
    .width(CommonConstants.FILL_WIDTH)
    .height(CommonConstants.FULL_HEIGHT)
    .backgroundColor($r('app.color.column_background_color'))
  }

  aboutToAppear() {
    let date = new Date()
    let year = date.getFullYear()
    let month = date.getMonth() + CommonConstants.PLUS_ONE
    let day = date.getDay()
    this.birthdate = CommonUtils.getBirthDateValue(year, month, day)

    let context = getContext(this)
    if ((CommonUtils.isEmpty(context)) || (CommonUtils.isEmpty(context.resourceManager))) {
      Logger.error(CommonConstants.TAG_HOME, 'context or resourceManager is null')
      return
    }
    let manager = context.resourceManager
    manager.getStringValue($r('app.string.default_sex').id, (error, sexValue) => {
      if (!CommonUtils.isEmpty(error)) {
        Logger.error(CommonConstants.TAG_HOME, 'error = ' + JSON.stringify(error))
      } else {
        this.sex = sexValue
      }
    })
  }
}