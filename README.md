# SetupBox_Client

debian package : SetupBox.deb(md5sum - 311a38c85be2970517aa766649fcba5c)
To install, type 'sudo dpkg -i Setupbox.deb'

If you aren't on Debian Linux, copy src/SetupBox and src/SetupBox_client to /usr/local/bin.
package httpie is needed.(sudo apt-get install httpie)

To install and run SetupBox, just type SetupBox --install on a directory where you want to clone.
After authentication, SetupBox_client run as daemon on directory 'SetupBox'.
If you turn off SetupBox client, use kill command.

** If server doesn't run, authentication fail. Please run SetupBox server and register your Email on Web-page. **
