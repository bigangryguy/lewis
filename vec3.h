#pragma once

#include <math.h>
#include <stdlib.h>
#include <iostream>

namespace lewis
{
	class vec3
	{
	private:
		double e[3];
	public:
		vec3() : vec3(0.0, 0.0, 0.0) {}
		vec3(double e0, double e1, double e2)
			: e{e0, e1, e2}
		{
		}

		inline double x() const { return e[0]; }
		inline double y() const { return e[1]; }
		inline double z() const { return e[2]; }
		inline double r() const { return e[0]; }
		inline double g() const { return e[1]; }
		inline double b() const { return e[2]; }

		inline const vec3& operator+() const { return *this; }
		inline vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }
		inline double operator[](int i) const { return e[i]; }
		inline double& operator[](int i) { return e[i]; }

		inline vec3& operator+=(const vec3& v2);
		inline vec3& operator-=(const vec3& v2);
		inline vec3& operator*=(const vec3& v2);
		inline vec3& operator/=(const vec3& v2);
		inline vec3& operator*=(const double t);
		inline vec3& operator/=(const double t);

		inline double length() const
		{
			return sqrt(e[0] * e[0] + e[1] * e[1] + e[2] * e[2]);
		}

		inline double squared_length() const
		{
			return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
		}

		inline void make_unit_vector();
	};

	inline std::istream& operator>>(std::istream& is, vec3& t)
	{
		is >> t[0] >> t[1] >> t[2];
		return is;
	}

	inline std::ostream& operator<<(std::ostream& os, const vec3& t)
	{
		os << t[0] << " " << t[1] << " " << t[2];
		return os;
	}

	inline vec3 operator+(const vec3& v1, const vec3& v2)
	{
		return vec3(v1[0] + v2[0], v1[1] + v2[1], v1[2] + v2[2]);
	}

	inline vec3 operator-(const vec3& v1, const vec3& v2)
	{
		return vec3(v1[0] - v2[0], v1[1] - v2[1], v1[2] - v2[2]);
	}

	inline vec3 operator*(const vec3& v1, const vec3& v2)
	{
		return vec3(v1[0] * v2[0], v1[1] * v2[1], v1[2] * v2[2]);
	}

	inline vec3 operator/(const vec3& v1, const vec3& v2)
	{
		return vec3(v1[0] / v2[0], v1[1] / v2[1], v1[2] / v2[2]);
	}

	inline vec3 operator*(double t, const vec3& v)
	{
		return vec3(t * v[0], t * v[1], t * v[2]);
	}

	inline vec3 operator/(vec3 v, double t)
	{
		return vec3(v[0] / t, v[1] / t, v[2] / t);
	}

	inline vec3 operator*(const vec3& v, double t)
	{
		return vec3(t * v[0], t * v[1], t * v[2]);
	}

	inline double dot(const vec3& v1, const vec3& v2)
	{
		return v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2];
	}

	inline vec3 cross(const vec3& v1, const vec3& v2)
	{
		return vec3(v1[1] * v2[2] - v1[2] * v2[1],
			-(v1[0] * v2[2] - v1[2] * v2[0]),
			v1[0] * v2[1] - v1[1] * v2[0]);
	}

	inline vec3 unit_vector(vec3 v)
	{
		return v / v.length();
	}

	inline vec3& vec3::operator+=(const vec3& v)
	{
		this->e[0] += v[0];
		this->e[1] += v[1];
		this->e[2] += v[2];
		return *this;
	}

	inline vec3& vec3::operator-=(const vec3& v)
	{
		this->e[0] -= v[0];
		this->e[1] -= v[1];
		this->e[2] -= v[2];
		return *this;
	}

	inline vec3& vec3::operator*=(const vec3& v)
	{
		this->e[0] *= v[0];
		this->e[1] *= v[1];
		this->e[2] *= v[2];
		return *this;
	}

	inline vec3& vec3::operator/=(const vec3& v)
	{
		this->e[0] /= v[0];
		this->e[1] /= v[1];
		this->e[2] /= v[2];
		return *this;
	}

	inline vec3& vec3::operator*=(const double t)
	{
		this->e[0] *= t;
		this->e[1] *= t;
		this->e[2] *= t;
		return *this;
	}

	inline vec3& vec3::operator/=(const double t)
	{
		double k = 1.0 / t;

		this->e[0] *= k;
		this->e[1] *= k;
		this->e[2] *= k;
		return *this;
	}

	inline void vec3::make_unit_vector()
	{
		double k = 1.0 / sqrt(this->e[0] * this->e[0] + this->e[1] * this->e[1] + this->e[2] * this->e[2]);
		this->e[0] *= k;
		this->e[1] *= k;
		this->e[2] *= k;
	}
}