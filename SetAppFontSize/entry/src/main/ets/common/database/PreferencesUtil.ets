import dataPreferences from '@ohos.data.preferences'
import StyleConstants from '../constants/StyleConstants'

const PREFERENCES_NAME = 'myPreferences'
const KEY_APP_FONT_SIZE = 'appFontSize'

export class PreferencesUtil {
  createPreferences(context) {
    globalThis.getFontPreferences = (() => {
      //获取首选项实例
      let preferences: Promise<dataPreferences.Preferences> = dataPreferences.getPreferences(context, PREFERENCES_NAME)
      return preferences
    })
  }

  saveDefaultFontSize(fontSize: number) {
    globalThis.getFontPreferences().then((preferences) => {
      preferences.has(KEY_APP_FONT_SIZE).then(async (isExist)=>{
        
      })
    })
  }
}