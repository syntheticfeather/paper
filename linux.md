# linux的基本操作指令

|指令|作用|
|----|----|
|sudo |管理员权限|
|apt update |处理软件包列表|
|apt upgrade| 升级软件包|
|apt install 软件包名 |安装软件包|
|apt remove 软件包名 |删除软件包|
|apt search 软件包名 |搜索软件包|
|sudo apt update| |
|sudo apt install open-vm-tools-desktop|一个增加帧率的工具|

# 关于ssh远端登录

## linux虚拟机上:

    下载openssh的服务端
    sudo apt install openssh-server

    查看ip地址
    ip addr 

    启动ssh服务
    sudo service ssh start

    或者设置为自启动
    sudo systemctl enable ssh

## vscode上:

    ssh插件下载

    输入 gcc@127.0.0.1

    设置一次config(一般选第一个)

    输入密码

    成功登录

# 免密登录:

## windows上:
    powershell下载openssh的客户端
    Add-WindowsCapability -Online -Name OpenSSH.Client~~~~0.0.1.0

    配置path。
    
    生成密钥
    ssh-keygen -t rsa 
    直接三下enter

    默认在C盘中的C:\Users\“用户名”\.ssh中。
    会有5个文件:
        id_rsa (称作密钥)
        id_rsa.pub (称作公钥)
        (两个都要使用)

## linux上:
    # 创建.shh目录
    mkdir ~/.ssh

    # 进入目录
    cd ~/.ssh

    # 创建 authorized_keys 文件
    touch authorized_keys

    将id_rsa.pub文件内容复制到authorized_keys中

## vscode上:
    左侧菜单栏远程资源管理中，对登陆的远端机进行config设置
    加上一行:
          IdentityFile "C:\Users\"用户名"\.ssh\id_rsa" (也就是密钥地址)

