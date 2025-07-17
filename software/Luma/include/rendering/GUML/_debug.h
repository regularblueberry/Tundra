#ifndef TUNGPU_HEADER
#endif // !TUNGPU_HEADER
#ifdef GUML_




GLubyte ShowGLErrors = 0;
GLubyte ShowShaderErrors = 0;
GLenum error;
GLbyte errorid = 0;
GLint compiled = GL_FALSE;
GLchar currentsection = UNDEFINED;
GLint maxLength = 0;
GLchar* shader_errorlog;

char errornames[7][sizeof("GL_INVALID_FRAMEBUFFER_OPERATION")] = {
"GL_INVALID_ENUM",
"GL_INVALID_VALUE", 
"GL_INVALID_OPERATION",
"GL_INVALID_FRAMEBUFFER_OPERATION",
"GL_OUT_OF_MEMORY",
"GL_STACK_UNDERFLOW",
"GL_STACK_OVERFLOW"
};


/*\------------------|
        DEBUG        |
/------------------*/
/*-------------------------------------------------------------------------------\
*\------------------|
       SYNOPSIS     |		GUML_ DEBUG MACROS
/------------------/		----------------------------	
* 
* 
* 
* 
* 
* 
---------------------------------------------------------------------------------*/
#define disable(disablee) if(0){disablee}
#define enable(enablee) if(1){enablee}

#define dump_GLERRORS if(ShowGLErrors){ error = glGetError(); while(error != GL_NO_ERROR){\
error = glGetError();                                                   \
                                                                        \
switch (error)                                                          \
 {                                                                      \
     case GL_INVALID_ENUM : errorid = 0; break;                         \
     case GL_INVALID_VALUE : errorid = 1; break;                        \
     case GL_INVALID_OPERATION : errorid = 2; break;                    \
     case GL_INVALID_FRAMEBUFFER_OPERATION : errorid = 3; break;        \
     case GL_OUT_OF_MEMORY : errorid = 4; break;                        \
     case GL_STACK_UNDERFLOW : errorid = 5; break;                      \
     case GL_STACK_OVERFLOW : errorid = 6; break;                       \
        default:                                                        \
             break;                                                      \
 }                                                                      \
switch (currentsection)                                                 \
{                                                                       \
        case DATA:                                                      \
printf("TUNDRA_GL_ERROR: %s LINE: %i FUNCTION: %s SECTION: %s\n",         \
 errornames[errorid], __LINE__, __func__, "DATA"); break;               \
        case FORMAT:                                                    \
printf("TUNDRA_GL_ERROR: %s LINE: %i FUNCTION: %s SECTION: %s\n",         \
 errornames[errorid], __LINE__, __func__, "FORMAT"); break;             \
        case UNDEFINED:                                                 \
printf("TUNDRA_GL_ERROR: %s LINE: %i FUNCTION: %s SECTION: %s\n",         \
 errornames[errorid], __LINE__, __func__, "UNDEFINED"); break;          \
	default:                                                        \
            break;                                                      \
}                                                                       \
}									\
}

#define check_ShaderCompileErrors if(ShowShaderErrors){                                         \
glGetShaderiv(tmpdata->selectedshader, GL_COMPILE_STATUS, &compiled);   if(!compiled){                   \
glGetShaderiv(tmpdata->selectedshader, GL_INFO_LOG_LENGTH, &maxLength);                                  \
shader_errorlog = malloc(maxLength);                                                            \
glGetShaderInfoLog(tmpdata->selectedshader, maxLength, &maxLength, shader_errorlog);                     \
printf("SHADER COMPILATION ERROR AT LINE %i\n LOG:\n %s", __LINE__, (char*)shader_errorlog);};  \
}

#endif // GUML_

