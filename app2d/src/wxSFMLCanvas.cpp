// ----------------------------------------------------------------------------
// wxSFMLCanvas.cpp
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// include files

#include <iostream>
/*
#include <wxSFMLCanvas.hpp>
#include <wx/dcclient.h> // wxPaintDC
#include <wx/display.h> // Display

#ifdef __WXGTK__
#   include <gdk/gdkx.h>
#   include <gtk/gtk.h>
#   include <wx/gtk/win_gtk.h>
#endif

// ----------------------------------------------------------------------------
wxSFMLCanvas::wxSFMLCanvas( wxWindow* Parent, wxWindowID Id, const wxPoint& Position, const wxSize& Size, long Style )
{

#ifdef __WXGTK__

    // GTK implementation requires to go deeper to find the
    // low-level X11 identifier of the widget
    //gtk_widget_realize( m_wxwindow );
    //gtk_widget_set_double_buffered( m_wxwindow, false );
    //Display* display = GDK_WINDOW_XDISPLAY( widget->window );
    //sf::RenderWindow::create( GDK_WINDOW_XWINDOW( widget->window ) );
    //gtk_widget_realize( m_wxwindow );
    //gtk_widget_set_double_buffered( m_wxwindow, false );
    //GdkWindow* Win = GTK_LAYOUT(m_wxwindow )->bin_window;
    //XFlush( GDK_WINDOW_XDISPLAY(Win) );
    //sf::RenderWindow::create( GDK_WINDOW_XWINDOW(Win) );

#else

    // Tested under Windows XP only (should work with X11
    // and other Windows versions - no idea about MacOS)
    sf::RenderWindow::Create( GetHandle() );
#endif

}

// ----------------------------------------------------------------------------
wxSFMLCanvas::~wxSFMLCanvas()
{
}

// ----------------------------------------------------------------------------
void wxSFMLCanvas::OnIdle( wxIdleEvent& )
{

    // send a paint message when the control is idle, to ensure maximum framerate
    this->Refresh();
    std::cout << "OnIdle" << std::endl;
}

// ----------------------------------------------------------------------------
void wxSFMLCanvas::OnPaint( wxPaintEvent& )
{

    // prepare the control to be repainted
    wxPaintDC Dc( this );

    // let the derived class do its specific stuff
    this->OnUpdate();

    // display on screen
    //TODO Display();
}
*/
