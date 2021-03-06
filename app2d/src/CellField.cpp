// ----------------------------------------------------------------------------
// CellField.cpp
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// include files

#include <app2d/CellField.hpp>
#include <gol/Rule.hpp>

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

// ----------------------------------------------------------------------------
CellField::CellField() :
    GenericCellField(GOL::Rule(2,3,3,3))
{

    // generate 8x8 image for a single cell
    sf::Image image;
    image.create( 8, 8 );
    for( unsigned int x = 0; x != 8; ++x )
        for( unsigned int y = 0; y != 8; ++y )
            image.setPixel( x, y, sf::Color(255,255,255) );
    m_CellTexture.loadFromImage( image, sf::IntRect(0,0,8,8) );
    m_CellTexture.setSmooth( true );
    m_CellSprite.setTexture( m_CellTexture );

    // add adjacent lookup table for 2D
    this->getAdjacentCellLookupTable().push_back( GOL::Vector2<int>(-1,-1) );
    this->getAdjacentCellLookupTable().push_back( GOL::Vector2<int>(-1,-0) );
    this->getAdjacentCellLookupTable().push_back( GOL::Vector2<int>(-1, 1) );
    this->getAdjacentCellLookupTable().push_back( GOL::Vector2<int>( 0,-1) );
    this->getAdjacentCellLookupTable().push_back( GOL::Vector2<int>( 0, 1) );
    this->getAdjacentCellLookupTable().push_back( GOL::Vector2<int>( 1,-1) );
    this->getAdjacentCellLookupTable().push_back( GOL::Vector2<int>( 1, 0) );
    this->getAdjacentCellLookupTable().push_back( GOL::Vector2<int>( 1, 1) );
}


// ----------------------------------------------------------------------------
CellField::~CellField()
{
}


// ----------------------------------------------------------------------------
void CellField::draw( sf::RenderTarget* target, sf::Vector2f viewSize, sf::Vector2f viewPosition, float zoomFactor )
{

    for( std::set<GOL::Vector2<int> >::const_iterator it = this->getActiveCellList().begin();
         it != this->getActiveCellList().end();
         ++it )
    {
        if( (viewPosition.x+static_cast<float>(it->x)*10.0f)*zoomFactor >= -10.0f &&
            (viewPosition.y+static_cast<float>(it->y)*10.0f)*zoomFactor >= -10.0f &&
            (viewPosition.x+static_cast<float>(it->x)*10.0f)*zoomFactor <= viewSize.x &&
            (viewPosition.y+static_cast<float>(it->y)*10.0f)*zoomFactor <= viewSize.y )
        {
            m_CellSprite.setPosition( ((it->x*10.0f)+viewPosition.x+1.0f)*zoomFactor, ((it->y*10.0f)+viewPosition.y+1.0f)*zoomFactor ); // shift by 1,1 (1.0*zoomFactor)
            m_CellSprite.setScale( zoomFactor, zoomFactor );
            target->draw( m_CellSprite );
        }
    }
}
