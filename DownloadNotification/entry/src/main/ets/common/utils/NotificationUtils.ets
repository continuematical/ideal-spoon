// @ts-nocheck
import wantAgent from '@ohos.app.ability.wantAgent'
import notification from '@ohos.notificationManager'
import CommonConstants from '../constants/CommonConstants'
import Logger from '../utils/Logger'

export function createWantAgent(bundleName: string, abilityName: string): Promise<WantAgent> {
  let wantInfo: wantAgent.WantAgentInfo = {
    wants: [
      {
        bundleName: bundleName,
        abilityName: abilityName
      }
    ],
    operationType: wantAgent.OperationType.START_ABILITY,
    requestCode: 0,
    wantAgentFlags: [wantAgent.WantAgentFlags.CONSTANT_FLAG],
  }
  return wantAgent.getWantAgent(wantInfo)
}

export function publishNotification(progress: number, title: string, wantAgentObj: wantAgent) {
  let template: notification.NotificationTemplate = {
    name: 'downloadTemplate',
    data: {
      progressValue: progress,
      progressMaxValue: CommonConstants.PROGRESS_TOTAL,
      isProgressIndeterminate: false
    }
  }

  let notificationRequest: notification.NotificationRequest = {
    id: CommonConstants.NOTIFICATION_ID,
    slotType: notification.SlotType.CONTENT_INFORMATION,
    template: template,
    content: {
      contentType: notification.ContentType.NOTIFICATION_CONTENT_BASIC_TEXT,
      normal: {
        title: `${title}:${CommonConstants.DOWNLOAD_FILE}`,
        text: '',
        additionalText: `${progress}%`
      }
    },
    wantAgent: wantAgentObj
  }

  notification.publish(notificationRequest).catch((error) => {
    Logger.error(`[ANS] publish failed,code is ${error.code},message is ${error.message}`)
  })
}