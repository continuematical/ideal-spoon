import dataPreferences from '@ohos.data.preferences'
import StyleConstants from '../constants/StyleConstants'
import Logger from '../util/Logger'

const PREFERENCES_NAME = 'myPreferences'
const KEY_APP_FONT_SIZE = 'appFontSize'

const TAG = '[PreferencesUtil]'

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
      preferences.has(KEY_APP_FONT_SIZE).then(async (isExist) => {
        Logger.info(TAG, 'preferences has changeFontSize is ' + isExist)
        if (!isExist) {
          await preferences.put(KEY_APP_FONT_SIZE, fontSize)
          preferences.flush()
        }
      }).catch((error) => {
        Logger.error(TAG, 'Has the value failed with err:' + error)
      })
    }).catch((error) => {
      Logger.error(TAG, 'Get the preferences failed,err:' + error)
    })
  }

  saveChangeFontSize(fontSize: number) {

  }

  async getChangeFontSize() {

  }

  async deleteChangeFontSize() {

  }
}

export default new PreferencesUtil()