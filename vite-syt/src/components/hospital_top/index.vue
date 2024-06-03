<template>
    <el-affix class="affix_container">
        <div class="header_wrapper">
            <div class="header_content">
                <div class="header_content_left finger">
                    <img
                        class="logo"
                        src="../../assets/logo.png"
                    />
                    <span class="logo_title">尚医通 预约挂号统一平台</span>
                </div>
                <div class="header_content_right">
                    <span class="helper">帮助中心</span>
                    <div class="login">登录/注册</div>
                    <el-dropdown>
                        
                    </el-dropdown>
                </div>
            </div>
        </div>
    </el-affix>
</template>

<script>
</script>

<style lang="scss">
.affix_container{
    width: 100%;
    height: 70px;
    z-index: 999;
}

.header_wrapper{
    width: 100%;
    height: 70px;
    display: flex;
    justify-content: center;
}

.header_content{
    width: 1200px;
    height: 70px;
    display: space-between;
    justify-content: center;

    .header_content_left{
        align-items: center;
        display: flex;
        height: 100%;
        padding: 10px;
        .logo{
            width: 50px;
            height: 50px;
            margin-right: 10px;
        }

        .logo_title{
            color: #55a6fe;
            font-size: 22px;
        }
    }

    .header_content_right{
        height: 100%;
        display: flex;
        justify-content: flex-end;
        align-items: center;
        font-size: 14px;

        .helper{
            margin-right: 10px;
            color: #7f7f7f;
        }

        .login{
            color: #999;
        }

        .login :hover{
            color: var(--el-color-primary);
        }
    }
}
</style>