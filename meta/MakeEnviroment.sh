#!/usr/bin/zsh

export HOME=/home/quang
export ENV=$HOME/Desktop/env
export SYSTEM=$HOME/Desktop/system
export META=$HOME/Desktop/meta
export DISK=$HOME/Desktop/disk

rm -rf $HOME/.ssh
rm -rf $HOME/.config/nvim/init.vim
rm -rf $HOME/.config/Code/User/settings.json
rm -rf $HOME/.config/Code/User/keybindings.json
rm -rf $HOME/.vscode/extensions/icons
rm -rf $HOME/.tmux.conf
rm -rf $HOME/.zshenv
rm -rf /etc/ssh/sshd_config
rm -rf /usr/bin/java

mkdir -p $HOME/.ssh
mkdir -p $HOME/.config/nvim
mkdir -p $HOME/.config/Code/User
mkdir -p $HOME/.vscode/extensions
mkdir -p $HOME/.local/bin

ln -s $DISK/icons $HOME/.vscode/extensions/icons
ln -s $META/settings.json $HOME/.config/Code/User/settings.json
ln -s $META/keybindings.json $HOME/.config/Code/User/keybindings.json
ln -s $META/.zshenv $HOME/.zshenv
ln -s $META/init.vim $HOME/.config/nvim/init.vim
ln -s $META/.tmux.conf $HOME/.tmux.conf
ln -s $META/config $HOME/.ssh/config
ln -s $META/sshd_config /etc/ssh/sshd_config
ln -s $DOTNET_HOME/dotnet /usr/bin/dotnet

apt update
apt install -y \
  ibus-unikey neovim tmux \
  curl zsh git build-essential python3.10-dev \
  openssh-server openssh-client sshpass jq \
  htop
apt full-upgrade -y
apt autoremove -y

sudo curl -L http://install.ohmyz.sh | sh
chsh -s $(which zsh)

cd $HOME/.local/bin; chmod +x *
cd $JAVA_HOME/bin; chmod +x *
cd $GO_HOME/bin; chmod +x *
cd $NODEJS_HOME/bin; chmod +x *
cd $TYPESRIPT_HOME/bin; chmod +x *
cd $DOTNET_HOME; chmod +x dotnet

python3 --version
java -version
go version
node -v
tsc -v
dotnet --version
perl --version
gcc --version

# DPKG
# Visual Studio Code
# Chrome

# EXTENSIONS
# Material Icon Theme
# Python
# Markdown All in One
# Markdown PDF
# Markdown Emoji
# Markdown Preview Mermaid Support

python3 $ENV/python/get-pip.py
# pip install

git config --global user.email 102quangnn@gmail.com
git config --global user.name quang

# CUSTOMIZE
# Appearance
# Screenlock
# Unikey

# SCRIPT
# Language
# docker


chmod +x /home/quang/Desktop/ide/env/go/pkg/tool/linux_amd64/*
/home/quang/Desktop/ide/env/go/bin/go install -v golang.org/x/tools/gopls@latest
/home/quang/Desktop/ide/env/go/bin/go install -v github.com/ramya-rao-a/go-outline@v0.0.0-20210608161538-9736a4bde949
/home/quang/Desktop/ide/env/go/bin/go install -v golang.org/x/tools/cmd/goimports@latest
/home/quang/Desktop/ide/env/go/bin/go install -v github.com/rogpeppe/godef@v1.1