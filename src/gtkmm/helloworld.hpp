// https://developer-old.gnome.org/gtkmm-tutorial/stable/sec-helloworld.html.en

#ifndef GTKMM_EXAMPLE_HELLOWORLD_H
#define GTKMM_EXAMPLE_HELLOWORLD_H

#include <gtkmm/button.h>
#include <gtkmm/window.h>

class HelloWorld : public Gtk::Window {

public:
    HelloWorld();

protected:
    // Signal handlers:
    void on_button_clicked();

    // Member widgets:
    Gtk::Button m_button;
};

#endif // GTKMM_EXAMPLE_HELLOWORLD_H
