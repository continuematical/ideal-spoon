import { defineConfig } from 'vite'
import vue from '@vitejs/plugin-vue'

//引用node提供的内置模块可以配置路径
//需要安装@types/node 声明文件
import path from 'path'

// https://vitejs.dev/config/
export default defineConfig({
  plugins: [vue()],
  //src文件夹配置别名
  resolve: {
    alias: {
      '@': path.resolve(__dirname, 'src')
    }
  }
})
