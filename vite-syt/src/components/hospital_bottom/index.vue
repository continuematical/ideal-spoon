<template>
    <div class="footer_wrapper">
        <div class="footer_content">
            <div class="footer_content_left">
                <span class="left_item">京ICP备 13018369号</span>
                <span class="left_item">电话挂号010-56253825</span>
            </div>

            <div class="footer_content_right">

            </div>
        </div>
    </div>
</template>

<script>
</script>

<style lang="scss">
.footer_wrapper{
    width: 100%;
    height: 50px;
    background: #f0f2f5;
    display: flex;
    justify-content: center;
    align-items: center;
    position: absolute;
    bottom: 0;
}

.footer_content{
    width: 1200px;
    height: 50px;
    display: flex;
    justify-content: space-between;

    .footer_content_left{
        display: flex;
        justify-content: center;
        align-items: center;
        height: 100%;
        color: #7f7f7f;
        .left_item{
            margin-left: 5px;
        }
    }

    .footer_content_right{

    }
}

</style>