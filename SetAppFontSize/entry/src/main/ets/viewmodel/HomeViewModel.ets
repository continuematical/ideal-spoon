import SettingData from '../common/bean/SettingData'

export class HomeViewModel {
  settingArr: Array<SettingData> = null

  initSettingData(): Array<SettingData> {
    if (this.settingArr === null) {
      this.settingArr = new Array<SettingData>()

      let settingData = new SettingData()
      settingData.settingName = $r('app.string.home_display_and_brightness')

      settingData = new SettingData()
      settingData.settingName = $r('app.string.home_voice')

      settingData = new SettingData()
      settingData.settingName = $r('app.string.home_app_management')
    }
    return this.settingArr
  }
}

export default new HomeViewModel()