import notification from '@ohos.notificationManager'
import image from '@ohos.multimedia.image'
import wantAgent from '@ohos.wantAgent'

@Entry
@Component
struct Index {
  @State message: string = 'Hello World'

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

  }
}