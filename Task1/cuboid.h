#ifndef CUBOID_H
#define CUBOID_H

//m is member types and M is function return types
template <class m>

class Cuboid
{
	private:
		m height;
		m width;
		m length;

	public:
		Cuboid(m w, m l, m h)
		{
			height = h;
			length = l;
			width = w;
		}

		m getVolume()
		{
			m volume = 0;
			volume = (length * height * width);
			return volume;
		}

		m getSurfaceArea()
		{
			m surfaceArea = 0;
			surfaceArea = (2*( (length*width) + (width*height) + (height*length) ) );

			return surfaceArea;
		}
};

#endif
