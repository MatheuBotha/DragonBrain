//
// Created by lemmus on 2016/09/09.
//


int main()
{
    char **arger = new char*[1];
    SettingsPackage *setts = new SettingsPackage();
    std::thread GUI_Thread(generateGUI, std::ref(arger), std::ref(setts));

    GUI_Thread.join();
    return 0;
}