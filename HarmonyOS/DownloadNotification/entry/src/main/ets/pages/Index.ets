import notification from '@ohos.notificationManager'
import image from '@ohos.multimedia.image'
import wantAgent from '@ohos.wantAgent'
import CommonConstants from '../common/constants/CommonConstants'

@Entry
@Component
struct Index {
  @State message: string = 'Hello World'
  @State downloadProgress: number = 0

  //普通文字通知
  // publishNotification() {
  //   let notificationRequest: notification.NotificationRequest = {
  //     id: 1, //通知ID
  //     slotType: notification.SlotType.SERVICE_INFORMATION, //通道类型
  //     //通知内容
  //     content: {
  //       //基本信息类型
  //       contentType: notification.ContentType.NOTIFICATION_CONTENT_BASIC_TEXT,
  //       normal: { //基本类型通知内容
  //         title: 'title',
  //         text: 'text',
  //         additionalText: 'addition'
  //       }
  //     }
  //   }
  //   //发布通知
  //   notification.publish(notificationRequest).then(() => {
  //     console.log('publish success')
  //   }).catch((error) => {
  //     console.error(`publish failed,dcode:${error.code},messeage:${error.message}`)
  //   })
  // }


  //图片通知
  // async publishPictureNotification() {
  //将路径转化为PixelMap对象
  //   let resourceManager = getContext(this).resourceManager
  //   let imageArray = await resourceManager.getMediaContent($r('app.media.app_icon').id)
  //   创建图片源实例
  //   let imageResource = image.createImageSource(imageArray.buffer)
  //   let pixelMap = await imageResource.createPixelMap()
  //
  //   let notificationRequest: notification.NotificationRequest = {
  //     id: 2,
  //     content: {
  //       contentType: notification.ContentType.NOTIFICATION_CONTENT_PICTURE,
  //       picture: {
  //         title: 'title',
  //         text: 'text',
  //         expandedTitle: 'expandedTitle',
  //         briefText: 'briefText',
  //         picture: pixelMap,
  //       }
  //     }
  //   }
  //
  //   notification.publish(notificationRequest).then(() => {
  //     console.info('publish success')
  //   }).catch((error) => {
  //     console.error(`publish failed,dcode:${error.code},message:${error.message}`)
  //   })
  // }


  //进度条通知
  // publishNotification() {
  //   //是否支持进度条模板
  //   notification.isSupportTemplate('downloadTemplate').then((data) => {
  //     console.info('[ANS] isSupportTemplate success')
  //
  //   }).catch((error) => {
  //     console.error(`[ANS] isSupportTemplate failed,error[${error}]`)
  //   })
  //构造进度条模板
  //   let template = {
  //     name: 'downloadTemplate',
  //     data: {
  //       progressValue: 60,
  //       progressMaxValue: 100
  //     }
  //   }
  //
  //   let notificationRequest: notification.NotificationRequest = {
  //     id: 3,
  //     content: {
  //       contentType: notification.ContentType.NOTIFICATION_CONTENT_BASIC_TEXT,
  //       normal: {
  //         title: '文件下载',
  //         text: 'senTemplate',
  //         additionalText: '60%'
  //       },
  //     },
  //     template: template,
  //   }
  //   notification.publish(notificationRequest).then(()=>{
  //     console.info('publish success')
  //   }).catch(error=>{
  //     console.error(`publish failed,dcode:${error.code},message:${error.message}`)
  //   })
  // }

  build() {
    Column() {
      Text($r('app.string.title'))
        .fontSize($r('app.float.title_font_size'))
        .fontWeight(CommonConstants.FONT_WEIGHT_LAGER)
        .width(CommonConstants.TITLE_WIDTH)
        .textAlign(TextAlign.Start)
        .margin({
          top: $r('app.float.title_margin_top'),
          left: $r('app.float.title_margin_top')
        })

      Row() {
        Column()

        Column() {
          Text(CommonConstants.DOWNLOAD_FILE)
            .fontSize($r('app.float.name_font_size'))
            .textAlign(TextAlign.Center)
            .fontWeight(CommonConstants.FONT_WEIGHT_LAGER)
            .lineHeight($r('app.float.name_font_height'))

          Text(`${this.downloadProgress}`)
            .fontSize($r('app.float.normal_font_size'))
            .lineHeight($r('app.float.name_font_height'))
            .opacity(CommonConstants.FONT_OPACITY)
        }
        .justifyContent(FlexAlign.SpaceBetween)
        .width(CommonConstants.FULL_LENGTH)

        Progress({
          value: this.downloadProgress,
          total: CommonConstants.PROGRESS_TOTAL
        })
          .width(CommonConstants.FULL_LENGTH)

        Row() {
          Text(CommonConstants.FILE_SIZE)
            .fontSize($r('app.float.normal_font_size'))
            .lineHeight($r('app.float.name_font_height'))
            .opacity(CommonConstants.FONT_OPACITY)
        }
        .width(CommonConstants.FULL_LENGTH)
      }
    }
  }

  async resume() {

  }

  async cancel() {

  }

  open() {

  }

  @Builder customButton(textResource: Resource, click: Function) {
    Button(textResource)
      .onClick(() => {
        click()
      })
  }

  @Builder cancelButton() {
    Button($r('app.string.button_cancel'))
  }
}

@Extend(Button) buttonStyle(){

}