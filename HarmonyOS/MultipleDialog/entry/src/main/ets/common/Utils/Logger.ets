import hilog from '@ohos.hilog'

export class Logger {
  private domain: number
  private prefix: string
  private format: string = '%{public}s,%{public}s'

  constructor(prefix: string = 'MyApp', domain: number = 0xFF00) {
    this.prefix = prefix
    this.domain = domain
  }

  debug(...args: any[]) {
    hilog.debug(this.domain, this.prefix, this.format, args)
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
}

export default new Logger()