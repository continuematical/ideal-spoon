import hilog from '@ohos.hilog'

export class Logger {
  private domain: number
  private prefix: string
  private format: string = `%{public},%{public}`

  constructor(prefix: string) {
    this.prefix = prefix
    this.domain = 0xFF00
  }

  info(...args: any[]) {
    hilog.info(this.domain, this.prefix, this.format, args)
  }

  warn(...args: any[]) {
    hilog.warn(this.domain, this.prefix, this.format, args)
  }

  error(...args: any[]) {
    hilog.error(this.domain, this.prefix, this.format, args)
  }

  debug(...args: any[]) {
    hilog.debug(this.domain, this.prefix, this.format, args)
  }

  fatal(...args: any[]) {
    hilog.fatal(this.domain, this.prefix, this.format, args)
  }

  isLoggable(level: number) {
    hilog.isLoggable(this.domain, this.prefix, level)
  }
}

export default new Logger('[SetFontSize]')