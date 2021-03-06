#ifndef GLES3_E1_2_VAOS_E1_2_VAOS_HPP
#define GLES3_E1_2_VAOS_E1_2_VAOS_HPP
/*
* OpenGL ES 3.0 Tutorial 1
*
* Draws a simple triangle with basic vertex and pixel shaders. Using Vertex Buffer Objects
*/

#include <FslDemoAppGLES3/DemoAppGLES3.hpp>
#include <FslGraphicsGLES3/GLProgram.hpp>
#include <FslGraphicsGLES3/GLTexture.hpp>

namespace Fsl
{
  class E1_2_VAOs : public DemoAppGLES3
  {
    struct UserData
    {
      // VertexBufferObject Ids
      GLuint vboIds[4];
      // VertexArrayObject Id
      GLuint vaoId[2];

      UserData()
      {
        vboIds[0] = GLES3::GLValues::INVALID_HANDLE;
        vboIds[1] = GLES3::GLValues::INVALID_HANDLE;
        vboIds[2] = GLES3::GLValues::INVALID_HANDLE;
        vboIds[3] = GLES3::GLValues::INVALID_HANDLE;
        vaoId[0] = GLES3::GLValues::INVALID_HANDLE;
        vaoId[1] = GLES3::GLValues::INVALID_HANDLE;
      }
    };

    GLES3::GLProgram m_program;
    UserData m_userData;

  public:
    E1_2_VAOs(const DemoAppConfig& config);
    ~E1_2_VAOs();
  protected:
    virtual void Update(const DemoTime& demoTime) override;
    virtual void Draw(const DemoTime& demoTime) override;
  private:
    void Cleanup();
  };
}

#endif
