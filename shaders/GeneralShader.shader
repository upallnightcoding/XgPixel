#version 330 core

// Object data format layout
//--------------------------
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoords;
layout (location = 3) in vec3 aColor;

//out vec2 TexCoords;

out VS_OUT {
    vec3 FragPos;
    vec3 Normal;
    vec2 TexCoords;
    vec4 FragPosLightSpace;
} vs_out;

// Object projection variables
//----------------------------
uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;
uniform mat4 lightSpaceMatrix;

void main()
{
    vs_out.FragPos = vec3(model * vec4(aPos, 1.0));
	
    vs_out.Normal = transpose(inverse(mat3(model))) * aNormal;
	
    vs_out.TexCoords = aTexCoords;
	
    vs_out.FragPosLightSpace = lightSpaceMatrix * vec4(vs_out.FragPos, 1.0);
	
	// Calculate point position
    gl_Position = projection * view * model * vec4(aPos, 1.0);
}
@
#version 330 core
out vec4 FragColor;

in VS_OUT {
    vec3 FragPos;
    vec3 Normal;
    vec2 TexCoords;
    vec4 FragPosLightSpace;
} fs_in;

uniform sampler2D diffuseTexture;
uniform sampler2D shadowMap;

uniform vec3 lightPos;
uniform vec3 viewPos;

float ShadowCalculation(vec4 fragPosLightSpace)
{
    // perform perspective divide
    vec3 projCoords = fragPosLightSpace.xyz / fragPosLightSpace.w;
	
    // transform to [0,1] range
    projCoords = projCoords * 0.5 + 0.5;
	
    // get closest depth value from light's perspective (using [0,1] range fragPosLight as coords)
    float closestDepth = texture(shadowMap, projCoords.xy).r; 
	
    // get depth of current fragment from light's perspective
    float currentDepth = projCoords.z;
	
    // check whether current frag pos is in shadow
    float shadow = currentDepth > closestDepth  ? 1.0 : 0.0;
	
	shadow = 0.0;

    return shadow;
}

void main()
{           
    vec3 color = texture(diffuseTexture, fs_in.TexCoords).rgb;
	
    vec3 normal = normalize(fs_in.Normal);
    vec3 lightColor = vec3(1.0);
	
    // ambient
    vec3 ambient = 0.7 * color;
	
    // diffuse
    vec3 lightDir = normalize(lightPos - fs_in.FragPos);
    float diff = max(dot(lightDir, normal), 0.0);
    vec3 diffuse = diff * lightColor;
	
    // specular
    vec3 viewDir = normalize(viewPos - fs_in.FragPos);
    vec3 reflectDir = reflect(-lightDir, normal);
    
	float specularStrength = 1.0;
    vec3 halfwayDir = normalize(lightDir + viewDir);  
    //spec = pow(max(dot(normal, halfwayDir), 0.0), 64.0);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), 64.0);
	spec = 0.0;
    vec3 specular = specularStrength * spec * lightColor; 
	
	//float specularStrength = 1.0;
	//vec3 viewDir = normalize(u_ViewPosition - FragPos);
	//vec3 reflectDir = reflect(-lightDir, norm);  
	//float spec = pow(max(dot(viewDir, reflectDir), 0.0), 30.0);
	//vec3 specularLight = specularStrength * spec * u_LightColor;
	
    // calculate shadow
    float shadow = ShadowCalculation(fs_in.FragPosLightSpace);                      
	shadow = 0.0;
    vec3 lighting = (ambient + (1.0 - shadow) * (diffuse + specular)) * color;    
    
    FragColor = vec4(lighting, 1.0);
}