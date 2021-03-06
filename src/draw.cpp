#include "../headers/draw.h"

void Draw::preparateScene(App &app){
	SDL_SetRenderDrawColor(app.renderer, 0, 0x99, 0xFF, 0xFF);
	SDL_RenderClear(app.renderer);
}

void Draw::drawRects(App &app){
	for(int i = 0 ; i < rects.size() ; i++){
		Rect *r = rects[i];
		if(r->visible){
//			std::cout << "[" << i+1<< "]"<< r.color.r << " " << r.color.g  << " " << r.color.b << " " << r.color.a << std::endl; 
			SDL_SetRenderDrawColor(app.renderer, r->color.r, r->color.g, r->color.b, r->color.a);
			SDL_RenderDrawRect(app.renderer, &r->rect);
		}
	}
}

void Draw::presentScene(App &app){
	SDL_RenderPresent(app.renderer);
}

Rect* Draw::createRect(int x, int y, int sizeX, int sizeY, bool visible){
	Rect *r = (Rect*)malloc(sizeof(Rect));
	SDL_Rect nr = { x-sizeX/2, y-sizeY/2, sizeX, sizeY };
	r->visible = visible;
	r->rect = nr;
	r->color.r = 0;
	r->color.g = 0;
	r->color.b = 0;
	r->color.a = 0xFF;
	rects.push_back(r);
	return r;
}

int Draw::getRectsSize(){
	return rects.size();
}

Color Draw::getRectColor(int index){
	return rects[index]->color;
}

void Draw::setRectColor(int index, Color color){
	rects[index]->color = color;
//	std::cout << "[" << index << "]" << rects[index].color.r << " " << rects[index].color.g  << " " << rects[index].color.b << " " << rects[index].color.a << std::endl; 
}

void Draw::drawTexts(App &app){
	SDL_Color color = { 0, 0, 0, 0xFF};
	for(int i = 0 ; i < texts.size() ; i++){
		Text *t = texts[i];
		if(t->visible){
			TTF_Font *font = TTF_OpenFont("/home/luan/fonts/Roboto-Regular.ttf", t->fontSize);
			int sizeX, sizeY;
			sizeX = t->sizeX;
			sizeY = t->sizeY;
			SDL_Rect txtBox = { t->x-sizeX/2, t->y-sizeY/2, sizeX, sizeY };
			SDL_Surface *txtSurface = TTF_RenderUTF8_Blended(font, t->text, color);
			SDL_Texture *txtTexture = SDL_CreateTextureFromSurface(app.renderer, txtSurface);
			SDL_RenderCopy(app.renderer, txtTexture, NULL, &txtBox);
			// Liberando recursos
			SDL_FreeSurface(txtSurface);
			SDL_DestroyTexture(txtTexture);
			TTF_CloseFont(font);
		}
	}
}

Text* Draw::createText(char* text, int x, int y, int sizeX, int sizeY, int fontSize){
	Text* newText = (Text*)malloc(sizeof(Text));
	std::cout << text << std::endl;
	newText->index = texts.size();
	newText->x = x;
	newText->y = y;
	newText->sizeX = sizeX;
	newText->sizeY = sizeY;
	newText->offX = 0;//offX;
	newText->offY = 0;//offY;	
	newText->fontSize = fontSize;
	newText->text = text;
	newText->visible = true;
	texts.push_back(newText);
	return newText;
}

int Draw::getTextsSize(){
	return texts.size();
}

Texture* Draw::createTexture(SDL_Texture *texture, int x, int y, int width, int height){
	Texture *newTexture = (Texture*)malloc(sizeof(Texture));
	newTexture->texture = texture;
	newTexture->x = x;
	newTexture->y = y;
	newTexture->w = width;
	newTexture->h = height;
	newTexture->visible = true;
	textures.push_back(newTexture);
	return newTexture;
}

void Draw::drawTextures(App &app){
	for(int i = 0 ; i < textures.size() ; i++){
		if(textures[i]->visible){
			blit(app, textures[i]);
		}
	}
}

void Draw::updateTextureVisibility(int index, bool newVisible){
	if(index < textures.size()){
		textures[index]->visible = newVisible;
	}
}

void Draw::updateTextureCoords(int index, int x, int y){
	if(index < textures.size()){
		textures[index]->x = x;
		textures[index]->y = y;
	}
}

char* Draw::getTextContent(int index){
	if(texts.size() > index && index > -1){
		return texts[index]->text;
	}
	return NULL;
}
